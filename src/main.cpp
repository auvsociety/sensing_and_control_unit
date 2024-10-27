#include <Arduino.h>

#include "communication/communication.hpp"
#include "depth_sensor/depth_sensor.hpp"
#include "imu/imu.hpp"
#include "lumen/lumen.hpp"
#include "orientation_filter/orientation_filter.hpp"
#include "thruster/thruster.hpp"
#include "diagnostics_led/diagnostics_led.hpp"
#include "oled/oled.hpp"
#include "bms/bms.hpp"


const int kRefreshIntervalInMs = 100;
const int kDisplayTimeInSec = 2;
using namespace sensing_and_control_unit;

Communication communication;
DepthSensor depth_sensor;
Imu imu;
Lumen lumen;
Thrusters thrusters;
OrientationFilter orientation_filter;
Diagnostics diagnostics;
Oled oled;
BMS bms;


void setup() {
  communication.initialize();
  depth_sensor.initialize();
  imu.initialize();
  lumen.initialize();
  thrusters.initialize();
  orientation_filter.initialize();
  diagnostics.initialize();
  oled.initialize(); 
  bms.initialize();
}

void loop() {
  static float last_time = 0, current_time = 0;

  static bool calibrate_flag = false;
  static bool diagnostics_flag = false;
  static bool pwm_flag = false;

  static int led_indicator = 0;
  static int pwm_values[kThrusterCount] = {0, 0, 0, 0, 0, 0};

  static float depth = 0;

  static float voltage = 0;
  static float current = 0;
  static float temperature = 0;

  static Vec3f acceleration{0, 0, 0};
  static Vec3f angular_velocity{0, 0, 0};
  static Vec3f magnetic_field{0, 0, 0};

  static Vec3f orientation{0, 0, 0};

  calibrate_flag = communication.getCalibrateFlag();
  diagnostics_flag = communication.getDiagnosticsFlag();

  if(calibrate_flag)
  {
      imu.calculateOffsets();
      depth_sensor.calculateOffsets();
  }
  if(diagnostics_flag)
  {
      led_indicator = communication.getLedIndicator();
      diagnostics.setLed(led_indicator);
  }

  voltage = bms.getVoltage();
  current = bms.getCurrent();
  temperature = bms.getTemperature();

  oled.display(voltage, current, temperature, kDisplayTimeInSec);

  current_time = millis();
  
  // Send data every 100ms
  if (current_time - last_time >= kRefreshIntervalInMs) {
    last_time = current_time;

    depth_sensor.update();
    depth_sensor.calibrate();
    imu.update();
    imu.calibrate();

    depth = depth_sensor.getDepth();
    acceleration = imu.getAcceleration();
    angular_velocity = imu.getAngularVelocity();
    magnetic_field = imu.getMagneticField();

    orientation = orientation_filter.getEulerAngles();

    communication.sendDepth(depth);

    communication.sendIMUData(acceleration, angular_velocity, magnetic_field);

    communication.sendOrientation(orientation);
  }
  pwm_flag = communication.getPWMFlag();
  if(pwm_flag)
  {
      for (int i = 0; i < kThrusterCount; i++)
      {
          pwm_values[i] = communication.getPWMValues(i);
      }
      thrusters.setPWMs(pwm_values);
  }

  communication.recieveCommands();
}