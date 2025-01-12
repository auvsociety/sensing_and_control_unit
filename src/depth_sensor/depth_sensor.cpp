#include "depth_sensor.hpp"

MS5837 sensor;

namespace sensing_and_control_unit {
DepthSensor::DepthSensor() {

}
DepthSensor::~DepthSensor() {

}

void DepthSensor::initialize() {
    while(!sensor.init())
    {
        Serial.println("Initialization failed .");
        delay(5000);
    }
    Serial.println("Initialization success");
    calculateOffsets();
}

void DepthSensor::calculateOffsets() {
     for(int i=0;i<100;i++)
     {
        update();
        depth_offset_+=depth_; 
     }
     depth_offset_/=100;
}

void DepthSensor::update() {
    sensor.read();
    depth_=sensor.depth();
}

void DepthSensor::calibrate() {
     depth_-=depth_offset_;
}

float DepthSensor::getDepth() { 
    update();
    calibrate();
    return depth_ ; }

}  // namespace sensing_and_control_unit