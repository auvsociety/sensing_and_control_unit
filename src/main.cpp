#include <Arduino.h>

#include "communication/communication.hpp"
#include "depth_sensor/depth_sensor.hpp"
#include "imu/imu.hpp"
#include "lumen/lumen.hpp"
#include "orientation_filter/orientation_filter.hpp"
#include "thruster/thruster.hpp"

const int kRefreshIntervalInMs = 100;
using namespace sensing_and_control_unit;

Communication communication;
DepthSensor depth_sensor;
Imu imu;
Lumen lumen;
Thrusters thrusters;
OrientationFilter orientation_filter;

void setup() {
  communication.initialize();
  depth_sensor.initialize(communication);
  imu.initialize(communication);
  lumen.initialize();
  thrusters.initialize();
  orientation_filter.initialize(kRefreshIntervalInMs);
}

void loop() {
  static float last_time = 0, current_time = 0;

  static float depth = 0;
  static int depth_raw_data = 0;

  static Vec3f raw_accelerometer_reading{0, 0, 0};
  static Vec3f raw_gyroscope_reading{0, 0, 0};
  static Vec3f raw_magnetometer_reading{0, 0, 0};

  static Vec3f acceleration{0, 0, 0};
  static Vec3f angular_velocity{0, 0, 0};
  static Vec3f magnetic_field{0, 0, 0};

  static Vec3f orientation{0, 0, 0};

  current_time = millis();

  // Send data every 100ms
  if (current_time - last_time >= kRefreshIntervalInMs) {
    last_time = current_time;

    depth_sensor.update();
    imu.update();

    depth_raw_data = depth_sensor.getRawReading();
    depth = depth_sensor.getDepth();

    raw_accelerometer_reading = imu.getRawAccelerometerReading();
    raw_gyroscope_reading = imu.getRawGyroscopeReading();
    raw_magnetometer_reading = imu.getRawMagnetometerReading();

    acceleration = imu.getAcceleration();
    angular_velocity = imu.getAngularVelocity();
    magnetic_field = imu.getMagneticField();

    orientation = orientation_filter.getEulerAngles();

    communication.sendDepthRawData(depth_raw_data);
    communication.sendDepth(depth);

    communication.sendIMURawData(raw_accelerometer_reading,
                                 raw_gyroscope_reading,
                                 raw_magnetometer_reading);
    communication.sendIMUData(acceleration, angular_velocity, magnetic_field);

    communication.sendOrientation(orientation);
  }

  communication.recieveCommands();
}