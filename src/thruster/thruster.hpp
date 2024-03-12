#ifndef SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP
#include <Servo.h>

#include "pins_info.hpp"
#include "thruster_info.hpp"

namespace sensing_and_control_unit {

/**
 * @file thruster.hpp
 * @brief Contains the declarartion of the Thrusters class for controlling and
 * managing thrusters.
 */

/**
 * @class Thrusters
 * @brief Controls and manages thrusters.
 *
 * This class provides methods for initializing thrusters and setting PWM
 * values.
 */

class Thrusters {
 private:
  /**
   * @brief Array of Servo objects for controlling thrusters.
   */
  Servo thrusters_[kThrusterCount];

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

  int32_t limitToMinMax(int32_t value, int32_t min, int32_t max);

 public:
  /**
   * @brief Constructor for the Thrusters class.
   *
   * Initializes the Thrusters class by creating Servo objects for each
   * thruster.
   */

  Thrusters();

  /**
   * @brief Destructor for the Thrusters class.
   *
   * Cleans up resources used by the Thrusters class.
   */

  ~Thrusters();

  /**
   * @brief Initializes the thrusters.
   *
   * This method sets up the Servo objects for each thruster.
   */

  void initialize();

  /**
   * @brief Sets PWM values for the thrusters.
   *
   * @param pwm_values An array of PWM values for each thruster.
   */

  void setPWMs(const int32_t pwm_values[kThrusterCount]);
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP