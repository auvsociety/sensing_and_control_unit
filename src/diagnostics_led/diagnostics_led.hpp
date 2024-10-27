#ifndef SENSIING_AND_CONTROL_UNIT_SRC_DIAGNOSTICS_LED_DIAGNOSTICS_LED_HPP
#define SENSIING_AND_CONTROL_UNIT_SRC_DIAGNOSTICS_LED_DIAGNOSTICS_LED_HPP

namespace sensing_and_control_unit {
class Diagnostics
{
private:
    /* data */  

public:
    Diagnostics(/* args */);
    ~Diagnostics();
    void initialize();
    void setLed(int led_indicator);
    
};
} // namespace sensing_and_control_unit
#endif // SENSIING_AND_CONTROL_UNIT_SRC_DIAGNOSTICS_LED_DIAGNOSTICS_LED_HPP