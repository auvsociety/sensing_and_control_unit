#include "depth_sensor.hpp"

namespace sensing_and_control_unit {
DepthSensor::DepthSensor() {}
DepthSensor::~DepthSensor() {}

void DepthSensor::initialize(Communication& communication) {}

void DepthSensor::update() {}

int DepthSensor::getRawReading() { return 0; }

float DepthSensor::getDepth() { return 0; }

}  // namespace sensing_and_control_unit