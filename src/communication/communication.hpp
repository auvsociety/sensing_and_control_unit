#ifndef SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#include "error.hpp"
#include "mat3x3.hpp"
#include "vec3.hpp"
#include "Fusion.h"

namespace sensing_and_control_unit {
class Communication {
 private:
  /* data */
 public:
  Communication(/* args */);
  ~Communication();
  FusionVector gyroscopeOffsets = {0.0f, 0.0f, 0.0f};
  FusionVector accelerometerOffsets = {0.0f, 0.0f, 0.0f};
  FusionMatrix magnetometerSoftIronOffsets = {0.971, -0.048, -0.024, -0.048, 0.972, -0.011, -0.024, -0.011, 1.063};
  FusionVector magnetometerHardIronOffsets = {57.59, 88.22, 74.47};
  float depthSensorOffset;
  void initialize();

  Vec3f getAccelerometerOffsets();
  Vec3f getGyroscopeOffsets();
  Vec3f getMagnetometerSoftIronOffsets();
  Mat3x3f getMagnetometerHardIronOffsets();

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