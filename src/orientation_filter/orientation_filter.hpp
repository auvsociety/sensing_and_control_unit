#ifndef ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP
#define ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP
#include <vec3.hpp>
#include <Arduino.h>
#include "Fusion.h"

namespace sensing_and_control_unit {
class OrientationFilter {
 private:
  /* data */
  FusionOffset offset;
  FusionAhrs ahrs;
  FusionEuler euler;
  bool start = true;
  double current_time=millis();
  double prev_time=current_time;
  double delta_time=0;


 public:
  OrientationFilter(/* args */);
  ~OrientationFilter();
  
  Vec3f orientation;
  void initialize(unsigned int);

  void update(Vec3f acceleration, Vec3f angular_velocity, Vec3f magnetic_field);

  Vec3f getEulerAngles();
};

}  // namespace sensing_and_control_unit

#endif  // ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP