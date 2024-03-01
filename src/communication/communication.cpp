#include "communication.hpp"

namespace sensing_and_control_unit {
Communication::Communication(/* args */) {}
Communication::~Communication() {}

void Communication::initialize() {}

Vec3f Communication::getAccelerometerOffsets() { return Vec3f(); }

Vec3f Communication::getGyroscopeOffsets() { return Vec3f(); }

Vec3f Communication::getMagnetometerSoftIronOffsets() { return Vec3f(); }

Mat3x3f Communication::getMagnetometerHardIronOffsets() { return Mat3x3f(); }

void Communication::sendOrientation(Vec3f orientation){};

void Communication::sendIMURawData(Vec3i accelerometer, Vec3i gyroscope,
                                   Vec3i magnetometer){};

void Communication::sendIMUData(Vec3f acceleration, Vec3f angular_velocity,
                                Vec3f magnetic_field){};

void Communication::sendDepthRawData(int depth){};

void Communication::sendDepth(float depth){};

void Communication::logMessage(const char *message, ErrorLevel error_level){};

void Communication::recieveCommands(){};

}  // namespace sensing_and_control_unit
