#ifndef SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#include "communication/communication.hpp"
namespace sensing_and_control_unit {
class DepthSensor {
 private:
  /* data */
 public:
  DepthSensor(/* args */);
  ~DepthSensor();
  void initialize(Communication& communication);
  void update();
  int getRawReading();
  float getDepth();
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP