// thruster.cpp

#include "thruster.hpp"

namespace sensing_and_control_unit {

/**
 * @file thruster.cpp
 * @brief Implements the methods of the Thrusters class for controlling and
 * managing thrusters.
 */

// Constructor
Thrusters::Thrusters() {}

// Destructor
Thrusters::~Thrusters() {}

/**
 *
 * @brief Initializes the thrusters, sets initial PWM for idle state.
 *
 * This function attaches each thruster to its designated pin, sets PWM to
 * kInitThrusterPwm (idle state), Prepares thrusters for control without active
 * propulsion.
 *
 * @note Ensure that thrusters_[] and kThrusterPins[] are correctly configured.
 *
 * @param None
 * @return None
 */

void Thrusters::initialize() {
  for (int thruster_index = 0; thruster_index < kThrusterCount;
       thruster_index++) {
    thrusters_[thruster_index].attach(kThrusterPins[thruster_index]);
    thrusters_[thruster_index].writeMicroseconds(kInitThrusterPwm);
  }
}

/**
 * @brief Set thruster PWM values.
 *
 * This function updates the PWM values for each thruster based on the provided
 * array.
 *
 * @note Ensure that thrusters_[] is initialized and configured correctly.
 *
 * @param pwm_values An array of int32_t values holding PWM values for each
 * thruster. The array size should be kThrusterCount.
 *
 * @return None
 */

void Thrusters::setPWMs(const int32_t pwm_values[kThrusterCount]) {
  uint32_t pwm_value = 0;
  for (int thruster_index = 0; thruster_index < kThrusterCount;
       thruster_index++) {
    pwm_value = pwm_values[thruster_index];

    // limiting PWM value to the specified range
    pwm_value = limitToMinMax(pwm_value, kMinPwmValue, kMaxPwmValue);

    thrusters_[thruster_index].writeMicroseconds(pwm_value);
  }
}

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

int32_t Thrusters::limitToMinMax(int32_t value, int32_t min, int32_t max) {
  if (value < min) {
    value = min;
  } else if (value > max) {
    value = max;
  }
  return value;
}
}  // namespace sensing_and_control_unit
