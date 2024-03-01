#ifndef ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP
#define ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP
#include <vec3.hpp>
namespace sensing_and_control_unit {
class OrientationFilter {
 private:
  /* data */
 public:
  OrientationFilter(/* args */);
  ~OrientationFilter();

  void initialize();

  void update(Vec3f acceleration, Vec3f angular_velocity, Vec3f magnetic_field);

  Vec3f getEulerAngles();
};

}  // namespace sensing_and_control_unit

#endif  // ORIENTATION_FILTER_INCLUDE_ORIENTATION_FILTER_HPP