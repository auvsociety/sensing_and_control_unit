#ifndef SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#include "communication/communication.hpp"
#include "MS5837.h"
namespace sensing_and_control_unit {
class DepthSensor {
 private:
    float depth_ = 0;
    float depth_offset_ = 0;
  /* data */
 public:
  DepthSensor(/* args */);
  ~DepthSensor();
  void initialize();
  void calculateOffsets();
  void update();
  void calibrate();
  float getDepth();
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP