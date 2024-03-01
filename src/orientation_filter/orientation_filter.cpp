#include "orientation_filter.hpp"

namespace sensing_and_control_unit {
OrientationFilter::OrientationFilter() {}
OrientationFilter::~OrientationFilter() {}

void OrientationFilter::initialize() {}

void OrientationFilter::update(Vec3f acceleration, Vec3f angular_velocity,
                               Vec3f magnetic_field){};

Vec3f OrientationFilter::getEulerAngles() { return Vec3f(); }

}  // namespace sensing_and_control_unit