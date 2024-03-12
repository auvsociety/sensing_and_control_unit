// lumen.hpp

#include "lumen.hpp"

namespace sensing_and_control_unit {

/**
 * @file lumen.cpp
 * @brief Implements the methods of the Lumen class for controlling and managing
 * lumen.
 *
 * This file implements the functionality declared in lumen.hpp.
 */

Lumen::Lumen() {}
Lumen::~Lumen() {}

/**
 * @brief Initializes the lumen.
 *
 * This function attaches the lumen to its designated pin and sets brightness to
 * kMinBrightness, preparing it for use.
 *
 * @note Ensure that kLumenPin is correctly configured.
 *
 * @param None
 * @return None
 */

void Lumen::initialize() {
  lumen_.attach(kLumenPin);
  lumen_.writeMicroseconds(kMinBrightness);
}

/**
 * @brief Sets the brightness of the lumen.
 *
 * This function sets the brightness of the lumen based on the provided value.
 *
 * @param brightness The brightness value to be set. Should be between 0.0
 * and 1.0.
 * @return None
 */

void Lumen::setBrightness(float brightness) {
  int32_t pwm_value = map(brightness, 0, 1, kMinBrightness, kMaxBrightness);
  pwm_value = limitToMinMax(pwm_value, kMinBrightness, kMaxBrightness);
  lumen_.writeMicroseconds(pwm_value);
}

/**
 * @brief Turns on the lumen.
 *
 * This function sets the brightness of the lumen to its maximum value,
 * turning it on.
 *
 * @param None
 * @return None
 */

void Lumen::turnOn() { lumen_.writeMicroseconds(kMaxBrightness); }

/**
 * @brief Turns off the lumen.
 *
 * This function sets the brightness of the lumen to its minimum value,
 * turning it off.
 *
 * @param None
 * @return None
 */

void Lumen::turnOff() { lumen_.writeMicroseconds(kMinBrightness); }

/**
 * @brief Limits a value to a specified range.
 *
 * This function ensures that the input value is within the specified range.
 *
 * @param value The value to be limited.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 * @return The limited value within the specified range.
 */

int32_t Lumen::limitToMinMax(int32_t value, int32_t min, int32_t max) {
  if (value < min) {
    value = min;
  } else if (value > max) {
    value = max;
  }
  return value;
}

}  // namespace sensing_and_control_unit
