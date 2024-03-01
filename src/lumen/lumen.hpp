#ifndef SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#include <Servo.h>

#include "pins_info.hpp"

namespace sensing_and_control_unit {
class Lumen {
 private:
  Servo lumen_;

 public:
  Lumen(/* args */);
  ~Lumen();
  void initialize();
  void setBrightness(int brightness);
  void turnOn();
  void turnOff();
};
}  // namespace sensing_and_control_unit

#endif  // SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP