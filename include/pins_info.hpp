#ifndef SENSIING_AND_CONTROL_UNIT_INCLUDE_PINS_INFO_HPP
#define SENSIING_AND_CONTROL_UNIT_INCLUDE_PINS_INFO_HPP
#include <Arduino.h>

#include "thruster_info.hpp"
const uint8_t kThrusterPins[kThrusterCount] = {PA0, PA1, PA2, PA3,
                                               PA6, PB0, PA7};
const uint8_t kLumenPin = 9;
#endif  // SENSIING_AND_CONTROL_UNIT_INCLUDE_PINS_INFO_HPP