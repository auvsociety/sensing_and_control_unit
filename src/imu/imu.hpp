#ifndef SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP
#include "communication/communication.hpp"
#include "vec3.hpp"

namespace sensing_and_control_unit {
class Imu {
 private:
  /* data */
 public:
  Imu(/* args */);
  ~Imu();

  void initialize(Communication& communication);

  void update();

  Vec3i getRawAccelerometerReading();
  Vec3i getRawGyroscopeReading();
  Vec3i getRawMagnetometerReading();

  Vec3f getAcceleration();
  Vec3f getAngularVelocity();
  Vec3f getMagneticField();
};

}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_IMU_IMU_HPP