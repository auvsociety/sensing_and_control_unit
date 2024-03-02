#ifndef SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP
#include "communication/communication.hpp"
#include "vec3.hpp"
#include "sensor_info.hpp"
#include "mpu6050.hpp"
#include "Adafruit_FXOS8700.h"
#include "Fusion.h"



namespace sensing_and_control_unit {
class Imu {

 private:
  /* data */
  MPU6050 gyroscope;
  Adafruit_FXOS8700 accelerometerMagnetometer = Adafruit_FXOS8700(accelerometerAddress , magnetometerAddress);

  const FusionMatrix gyroscopeMisalignment = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  const FusionVector gyroscopeSensitivity = {GYROSCOPE_SENSITIVITY_250, GYROSCOPE_SENSITIVITY_250, GYROSCOPE_SENSITIVITY_250};
  FusionVector gyroscopeOffsets = {0.0f, 0.0f, 0.0f};
  const FusionMatrix accelerometerMisalignment = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  const FusionVector accelerometerSensitivity = {ACCELERO_METER_SENSITIVITY_2,ACCELERO_METER_SENSITIVITY_2, ACCELERO_METER_SENSITIVITY_2};
  FusionVector accelerometerOffsets = {0.0f, 0.0f, 0.0f};
  FusionMatrix magnetometerSoftIronOffsets = {0.971, -0.048, -0.024, -0.048, 0.972, -0.011, -0.024, -0.011, 1.063};
  FusionVector magnetometerHardIronOffsets = {57.59, 88.22, 74.47};

  bool accelerometer_magnetometer_status;
  bool gyroscope_status;

 public:
  Imu(/* args */);
  ~Imu();

  Vec3f raw_accelerometer_readings,raw_gyroscope_readings,raw_magnetometer_readings;
  Vec3f acceleration,angular_velocity,magnetic_field;

  void initialize(Communication& communication);

  void update();

  Vec3f getRawAccelerometerReading();
  Vec3f getRawGyroscopeReading();
  Vec3f getRawMagnetometerReading();

  Vec3f getAcceleration();
  Vec3f getAngularVelocity();
  Vec3f getMagneticField();
};

}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP