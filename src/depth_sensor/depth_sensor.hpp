#ifndef SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#include "communication/communication.hpp"
#include "MS5837.h"



namespace sensing_and_control_unit {
class DepthSensor {
 private:
  /* data */
  MS5837 depthSensor;
  float depth_sensor_offset;
  bool depth_sensor_status;
 public:
  DepthSensor(/* args */);
  ~DepthSensor();
  float raw_depth,depth;
  void initialize(Communication& communication);
  void update();
  int getRawReading();
  float getDepth();
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP