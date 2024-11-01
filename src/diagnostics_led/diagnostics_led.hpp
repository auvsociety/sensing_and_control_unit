#ifndef SENSING_AND_CONTROL_UNIT_SRC_DIAGNOSTICS_LED_DIAGNOSTICS_LED_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_DIAGNOSTICS_LED_DIAGNOSTICS_LED_HPP
#include <Arduino.h>
#include <stdint.h>

namespace sensing_and_control_unit {
class Diagnostics
{
private:
    static const int16_t kLedCount = 9; 
    const int16_t led_bitmask[kLedCount] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    const int8_t led_pinmap[kLedCount] = {PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8};
public:
    Diagnostics();
    ~Diagnostics();
    void initializeLED();
    void setLed(int16_t led_indicator);
    
};
} // namespace sensing_and_control_unit
#endif // SENSIING_AND_CONTROL_UNIT_SRC_DIAGNOSTICS_LED_DIAGNOSTICS_LED_HPP
