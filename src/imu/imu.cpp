#include "imu.hpp"

namespace sensing_and_control_unit {
Imu::Imu() {}
Imu::~Imu() {}

void Imu::initialize() {}

void Imu::update() {}

void Imu::calculateOffsets() {}

void Imu::calibrate() {}

Vec3f Imu::getAcceleration() { return Vec3f(); }

Vec3f Imu::getAngularVelocity() { return Vec3f(); }

Vec3f Imu::getMagneticField() { return Vec3f(); }

}  // namespace sensing_and_control_unit