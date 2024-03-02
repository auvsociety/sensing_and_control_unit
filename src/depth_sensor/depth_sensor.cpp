#include "depth_sensor.hpp"

namespace sensing_and_control_unit {
DepthSensor::DepthSensor() {}
DepthSensor::~DepthSensor() {}

void DepthSensor::initialize(Communication& communication) {
  depth_sensor_offset_ = communication.getDepthSensorOffset();
  depth_sensor_status_ = depth_sensor_.init();
  depth_sensor_.setFluidDensity(997);  // kg/m^3 (freshwater, 1029 for seawater)
}

void DepthSensor::update() {
  depth_sensor_.read();
  raw_depth_ = depth_sensor_.depth();
}

int DepthSensor::getRawReading() { return raw_depth_; }

float DepthSensor::getDepth() {
  depth_ = raw_depth_ - depth_sensor_offset_;
  return depth_;
}

}  // namespace sensing_and_control_unit