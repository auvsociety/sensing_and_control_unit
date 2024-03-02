#include "imu.hpp"

namespace sensing_and_control_unit {
Imu::Imu() {}
Imu::~Imu() {}

void Imu::initialize(Communication& communication) {
  accelerometer_magnetometer_ =
      Adafruit_FXOS8700(accelerometer_address, magnetometer_address);
  Vec3f accelerometer_offset_vec3_ = communication.getAccelerometerOffset();
  Vec3f gyroscope_offset_vec3_ = communication.getGyroscopeOffset();
  Vec3f hard_iron_offset_vec3_ = communication.getMagnetometerHardIronOffset();
  Mat3x3f soft_iron_matrix_mat3x3_ =
      communication.getMagnetometerSoftIronMatrix();

  accelerometer_offset_ = {accelerometer_offset_vec3_.x,
                           accelerometer_offset_vec3_.y,
                           accelerometer_offset_vec3_.z};
  gyroscope_offset_ = {gyroscope_offset_vec3_.x, gyroscope_offset_vec3_.y,
                       gyroscope_offset_vec3_.z};
  hard_iron_offset_ = {hard_iron_offset_vec3_.x, hard_iron_offset_vec3_.y,
                       hard_iron_offset_vec3_.z};
  soft_iron_matrix_ = {
      soft_iron_matrix_mat3x3_.m00, soft_iron_matrix_mat3x3_.m01,
      soft_iron_matrix_mat3x3_.m02, soft_iron_matrix_mat3x3_.m10,
      soft_iron_matrix_mat3x3_.m11, soft_iron_matrix_mat3x3_.m12,
      soft_iron_matrix_mat3x3_.m20, soft_iron_matrix_mat3x3_.m21,
      soft_iron_matrix_mat3x3_.m22};

  accelerometer_magnetometer_status_ = accelerometer_magnetometer_.begin();
  gyroscope_status_ = gyroscope_.begin();
  gyroscope_.setAccelerometerRange(ACCELERO_METER_RANGE_2);
  gyroscope_.setGyroscopeRange(GYROSCOPE_RANGE_250);
  gyroscope_.setSampleRateDivider(0);
  gyroscope_.disableSleepMode();
}

void Imu::update() {
  sensors_event_t accel_event, mag_event;
  accelerometer_magnetometer_.getEvent(&accel_event, &mag_event);

  gyroscope_.getSensorsReadings(
      raw_accelerometer_reading_.y, raw_accelerometer_reading_.x,
      raw_accelerometer_reading_.z, raw_gyroscope_reading_.y,
      raw_gyroscope_reading_.x, raw_gyroscope_reading_.z);
  raw_accelerometer_reading_.y =
      -raw_accelerometer_reading_.y;  // Data changed to match the orientation
                                      // of both sensors in marty)
  raw_gyroscope_reading_.y = -raw_accelerometer_reading_.y;

  raw_magnetometer_reading_ = {mag_event.magnetic.x, mag_event.magnetic.y,
                               mag_event.magnetic.z};
}

Vec3f Imu::getRawAccelerometerReading() { return raw_accelerometer_reading_; }

Vec3f Imu::getRawGyroscopeReading() { return raw_gyroscope_reading_; }

Vec3f Imu::getRawMagnetometerReading() { return raw_magnetometer_reading_; }

Vec3f Imu::getAcceleration() {
  FusionVector accelerometer = {raw_accelerometer_reading_.x,
                                raw_accelerometer_reading_.y,
                                raw_accelerometer_reading_.z};
  accelerometer = FusionCalibrationInertial(
      accelerometer, accelerometer_misalignment_, accelerometer_sensitivity_,
      accelerometer_offset_);
  acceleration_ = {accelerometer.axis.x, accelerometer.axis.y,
                   accelerometer.axis.z};
  return acceleration_;
}

Vec3f Imu::getAngularVelocity() {
  FusionVector gyroscope = {raw_gyroscope_reading_.x, raw_gyroscope_reading_.y,
                            raw_gyroscope_reading_.z};
  gyroscope =
      FusionCalibrationInertial(gyroscope, gyroscope_misalignment_,
                                gyroscope_sensitivity_, gyroscope_offset_);
  angular_velocity_ = {gyroscope.axis.x, gyroscope.axis.y, gyroscope.axis.z};
  return angular_velocity_;
}

Vec3f Imu::getMagneticField() {
  FusionVector magnetometer;
  magnetometer = FusionCalibrationMagnetic(magnetometer, soft_iron_matrix,
                                           hard_iron_offset);
  magnetic_field = {magnetometer.axis.x, magnetometer.axis.y,
                    magnetometer.axis.z};
  return magnetic_field;
}

}  // namespace sensing_and_control_unit
