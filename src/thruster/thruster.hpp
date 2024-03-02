#ifndef SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP
#include <Servo.h>

#include "pins_info.hpp"
#include "thruster_info.hpp"
namespace sensing_and_control_unit {
class Thrusters {
 private:
  Servo thrusters_[kThrusterCount];
  int32_t limitToMinMax(int32_t value, int32_t min, int32_t max);

 public:
  Thrusters();
  ~Thrusters();
  void initialize();
  void setPWMs(const int32_t pwm_values[kThrusterCount]);
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP