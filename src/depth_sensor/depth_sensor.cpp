#include "depth_sensor.hpp"

namespace sensing_and_control_unit {
DepthSensor::DepthSensor() {}
DepthSensor::~DepthSensor() {}

void DepthSensor::initialize(Communication& communication) {
    depth_sensor_offset = communication.depthSensorOffset;
    depth_sensor_status= depthSensor.init();
    depthSensor.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)
}

void DepthSensor::update() {
    depthSensor.read();
    raw_depth=depthSensor.depth();
}

int DepthSensor::getRawReading() { 
    return raw_depth;
}

float DepthSensor::getDepth() { 
    depth = raw_depth - depth_sensor_offset;
    return depth;
}

}  // namespace sensing_and_control_unit