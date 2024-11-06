#ifndef ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP
#define ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP
#include "vec3.hpp"
#include "imu/imu.hpp"
#include "Fusion/Fusion.h"
#include <Arduino.h>

namespace sensing_and_control_unit{
class OrientationFilter {
 private:
  long int current_time=0, elapsed_time=0, delta_time=0;
  int sample_rate = 100;
  Vec3f orientation,earth_accel;

  FusionOffset offset;
  FusionAhrs ahrs;

 public:
  OrientationFilter(Vec3f acceleration, Vec3f angular_velocity, Vec3f magnetic_field);
  ~OrientationFilter();

  void initialize();

  void update(Vec3f acceleration, Vec3f angular_velocity, Vec3f magnetic_field);

  Vec3f getEulerAngles();
};

}  // namespace sensing_and_control_unit

#endif  // ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP
