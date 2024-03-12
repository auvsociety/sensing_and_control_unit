#ifndef SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#include <Arduino.h>
#include <Servo.h>

#include "pins_info.hpp"

namespace sensing_and_control_unit {

/**
 * @file lumen.hpp
 * @brief Contains the declaration of the Lumen class for controlling and
 * managing lumen.
 */

/**
 * @class Lumen
 * @brief Controls and manages the lumen.
 *
 * This class provides methods for initializing the lumen, setting its
 * brightness, turning it on, and turning it off.
 */

class Lumen {
 private:
  /**
   * @brief Servo object for controlling lumen brightness.
   */

  Servo lumen_;

  /**
   * @brief Minimum PWM value for lumen brightness.
   */

  int32_t kMinBrightness = 1100;

  /**
   * @brief Maximum PWM value for lumen brightness.
   */

  int32_t kMaxBrightness = 1900;

  /**
   * @brief Limits a value to a specified range.
   *
   * @param value The value to be limited.
   * @param min The minimum value of the range.
   * @param max The maximum value of the range.
   * @return The limited value within the specified range.
   */

  int32_t limitToMinMax(int32_t value, int32_t min, int32_t max);

 public:
  /**
   * @brief Constructor for the Lumen class.
   *
   * Initializes the Lumen class by creating a Servo object.
   */

  Lumen(/* args */);

  /**
   * @brief Destructor for the Lumen class.
   *
   * Cleans up resources used by the Lumen class.
   */

  ~Lumen();

  /**
   * @brief Initializes the lumen.
   *
   * This method sets up the Servo object for controlling lumen brightness.
   */

  void initialize();

  /**
   * @brief Sets the brightness of the lumen.
   *
   * @param brightness The brightness value to be set, ranging from 0.0 to 1.0.
   */

  void setBrightness(float brightness);

  /**
   * @brief Turns on the lumen.
   *
   * This method sets the brightness of the lumen to its maximum value, turning
   * it on.
   */
  void turnOn();

  /**
   * @brief Turns off the lumen.
   *
   * This method sets the brightness of the lumen to its minimum value, turning
   * it off.
   */

  void turnOff();
};
}  // namespace sensing_and_control_unit

#endif  // SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP