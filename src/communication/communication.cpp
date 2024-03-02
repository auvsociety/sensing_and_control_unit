#include "communication.hpp"

namespace sensing_and_control_unit {
Communication::Communication(/* args */) {}
Communication::~Communication() {}

void Communication::initialize() {}

Vec3f Communication::getAccelerometerOffset() { return Vec3f(); }

Vec3f Communication::getGyroscopeOffset() { return Vec3f(); }

Vec3f Communication::getMagnetometerHardIronOffset() { return Vec3f(); }

Mat3x3f Communication::getMagnetometerSoftIronMatrix() { return Mat3x3f(); }

float Communication::getDepthSensorOffset() { return float(); }

void Communication::sendOrientation(Vec3f orientation){};

void Communication::sendIMURawData(Vec3f accelerometer, Vec3f gyroscope,
                                   Vec3f magnetometer){};

void Communication::sendIMUData(Vec3f acceleration, Vec3f angular_velocity,
                                Vec3f magnetic_field){};

void Communication::sendDepthRawData(int depth){};

void Communication::sendDepth(float depth){};

void Communication::logMessage(const char *message, ErrorLevel error_level){};

void Communication::recieveCommands(){};

}  // namespace sensing_and_control_unit
