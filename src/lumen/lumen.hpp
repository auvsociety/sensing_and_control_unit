#ifndef SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#include <Servo.h>
#include <Arduino.h>
#include "pins_info.hpp"

namespace sensing_and_control_unit {
class Lumen {
 private:
  Servo lumen_;
  int32_t kMinBrightness = 1100;
  int32_t kMaxBrightness = 1900;
  int32_t limitToMinMax(int32_t value, int32_t min, int32_t max);
 public:
  Lumen(/* args */);
  ~Lumen();
  void initialize();
  void setBrightness(float brightness);
  void turnOn();
  void turnOff();
};
}  // namespace sensing_and_control_unit

#endif  // SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP