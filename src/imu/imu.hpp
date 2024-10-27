#ifndef SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP
#include "communication/communication.hpp"
#include "vec3.hpp"
#include "mat3x3.hpp"

namespace sensing_and_control_unit {
class Imu {
 private:
  Vec3f acceleration_{0, 0, 0};
  Vec3f angular_velocity_{0, 0, 0};
  Vec3f magnetic_field_{0, 0, 0};
  Vec3f accelerometer_offset_{0, 0, 0};
  Vec3f gyroscope_offset_{0, 0, 0};
  Vec3f magnetometer_hard_iron_offset_{0, 0, 0};
  Mat3x3f magnetometer_soft_iron_offset_{1, 0, 0, 0, 1, 0, 0, 0, 1};

 public:
  Imu(/* args */);
  ~Imu();

  void initialize();
  void calculateOffsets();
  void update();
  void calibrate();

  Vec3f getAcceleration();
  Vec3f getAngularVelocity();
  Vec3f getMagneticField();
};

}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP