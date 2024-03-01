#include "imu.hpp"

namespace sensing_and_control_unit {
Imu::Imu() {}
Imu::~Imu() {}

void Imu::initialize(Communication& communication) {}

void Imu::update() {}

Vec3i Imu::getRawAccelerometerReading() { return Vec3i(); }

Vec3i Imu::getRawGyroscopeReading() { return Vec3i(); }

Vec3i Imu::getRawMagnetometerReading() { return Vec3i(); }

Vec3f Imu::getAcceleration() { return Vec3f(); }

Vec3f Imu::getAngularVelocity() { return Vec3f(); }

Vec3f Imu::getMagneticField() { return Vec3f(); }

}  // namespace sensing_and_control_unit