#ifndef SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#include "MS5837.h"
#include "communication/communication.hpp"

namespace sensing_and_control_unit {
class DepthSensor {
 private:
  /* data */
  MS5837 depth_sensor_;
  float raw_depth_;
  float depth_;
  float depth_sensor_offset_;
  bool depth_sensor_status_;

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