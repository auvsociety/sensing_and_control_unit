#include "diagnostics_led.hpp"

namespace sensing_and_control_unit {

Diagnostics::Diagnostics() {}
Diagnostics::~Diagnostics() {}

void Diagnostics::initializeLED() 
{
    for(int pin_index=0;pin_index<kLedCount;pin_index++)
    {
        pinMode(led_pinmap[pin_index],OUTPUT);
        digitalWrite(led_pinmap[pin_index],HIGH);
    }
}

void Diagnostics::setLed(int16_t led_indicator) 
{
    for(int pin_index=0;pin_index<kLedCount;pin_index++)
    {
        if(led_indicator & led_bitmask[pin_index])
        {
            digitalWrite(led_pinmap[pin_index],LOW);
        }
        else
        {
            digitalWrite(led_pinmap[pin_index],HIGH);
        }
    }
}
}  // namespace sensing_and_control_unit



