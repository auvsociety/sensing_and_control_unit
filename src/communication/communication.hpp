#ifndef SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#include "Fusion.h"
#include "error.hpp"
#include "mat3x3.hpp"
#include "vec3.hpp"

namespace sensing_and_control_unit {
class Communication {
 private:
  /* data */
 public:
  Communication(/* args */);
  ~Communication();
  void initialize();

<<<<<<< HEAD
<<<<<<< HEAD
  Vec3f getAccelerometerOffset();
  Vec3f getGyroscopeOffset();
  Vec3f getMagnetometerHardIronOffset();
  Mat3x3f getMagnetometerSoftIronMatrix();
  float getDepthSensorOffset();
=======
=======
>>>>>>> origin/main
  float getDepthSensorOffset();
  Vec3f getAccelerometerOffsets();
  Vec3f getGyroscopeOffsets();
  Vec3f getMagnetometerSoftIronOffsets();
  Mat3x3f getMagnetometerHardIronOffsets();
>>>>>>> origin/main

  void sendOrientation(Vec3f orientation);
  void sendIMURawData(Vec3f accelerometer, Vec3f gyroscope, Vec3f magnetometer);
  void sendIMUData(Vec3f acceleration, Vec3f angular_velocity,
                   Vec3f magnetic_field);
  void sendDepthRawData(int depth);
  void sendDepth(float depth);

  void logMessage(const char *message, ErrorLevel error_level);
  void recieveCommands();
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP