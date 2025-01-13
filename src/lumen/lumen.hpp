#ifndef SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#include <Servo.h>
#include "pins_info.hpp"
#include "Arduino.h"

namespace sensing_and_control_unit {
class Lumen {
 private:
  Servo lumen_;
  static const int min_pwm = 1100;
  static const int max_pwm = 1900;

 public:
  Lumen();
  ~Lumen();
  void initialize();
  void setBrightness(int brightness);
};
}  // namespace sensing_and_control_unit

#endif  // SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
