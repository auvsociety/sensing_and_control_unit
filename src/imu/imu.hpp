#ifndef SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP
#include "Adafruit_FXOS8700.h"
#include "Fusion.h"
#include "communication/communication.hpp"
#include "mpu6050.hpp"
#include "sensor_info.hpp"
#include "vec3.hpp"

namespace sensing_and_control_unit {
class Imu {
 private:
  MPU6050 gyroscope_;
  Adafruit_FXOS8700 accelerometer_magnetometer_;

  const FusionMatrix gyroscope_misalignment_ = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
                                                0.0f, 0.0f, 0.0f, 1.0f};
  const FusionVector gyroscope_sensitivity_ = {GYROSCOPE_SENSITIVITY_250,
                                               GYROSCOPE_SENSITIVITY_250,
                                               GYROSCOPE_SENSITIVITY_250};
  FusionVector gyroscope_offset_ = {0.0f, 0.0f, 0.0f};

  const FusionMatrix accelerometer_misalignment_ = {
      1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  const FusionVector accelerometer_sensitivity_ = {
      ACCELERO_METER_SENSITIVITY_2, ACCELERO_METER_SENSITIVITY_2,
      ACCELERO_METER_SENSITIVITY_2};
  FusionVector accelerometer_offset_ = {0.0f, 0.0f, 0.0f};

  FusionMatrix soft_iron_matrix_ = {0.971,  -0.048, -0.024, -0.048, 0.972,
                                    -0.011, -0.024, -0.011, 1.063};
  FusionVector hard_iron_offset_ = {57.59, 88.22, 74.47};

  Vec3f raw_accelerometer_reading_, raw_gyroscope_reading_,
      raw_magnetometer_reading_;

  Vec3f acceleration_, angular_velocity_, magnetic_field_;

  bool accelerometer_magnetometer_status_;
  bool gyroscope_status_;

 public:
  Imu(/* args */);
  ~Imu();
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