#include "lumen.hpp"

namespace sensing_and_control_unit {
Lumen::Lumen() {}
Lumen::~Lumen() {}

void Lumen::initialize() {
  lumen_.attach(kLumenPin);
  lumen_.writeMicroseconds(kMinBrightness);
}

void Lumen::setBrightness(float brightness) {
  int32_t pwm_value = map(brightness, 0, 1, kMinBrightness, kMaxBrightness);
  pwm_value = limitToMinMax(pwm_value, kMinBrightness, kMaxBrightness);
  lumen_.writeMicroseconds(pwm_value);
}

void Lumen::turnOn() { lumen_.writeMicroseconds(kMaxBrightness); }

void Lumen::turnOff() { lumen_.writeMicroseconds(kMinBrightness); }

int32_t Lumen::limitToMinMax(int32_t value, int32_t min, int32_t max) {
  if (value < min) {
    value = min;
  } else if (value > max) {
    value = max;
  }
  return value;
}

}  // namespace sensing_and_control_unit
