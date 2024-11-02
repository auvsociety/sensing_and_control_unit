#include "thruster.hpp"

namespace sensing_and_control_unit {
Thrusters::Thrusters() {}
Thrusters::~Thrusters() {}

void Thrusters::initialize()
{
    for(int thruster_index=0;thruster_index<kThrusterCount;thruster_index++)
    {
        thrusters_[thruster_index].attach(kThrusterPins[thruster_index]);
        thrusters_[thruster_index].writeMicroseconds(kThrusterNeutralPWM);
    }
}

void Thrusters::setPWMs(int pwm_values[kThrusterCount])
{
    int pwm_value;
    for(int thruster_index=0;thruster_index<kThrusterCount;thruster_index++)
    {
        pwm_value = pwm_values[thruster_index];
        thrusters_[thruster_index].writeMicroseconds(pwm_value);
    }

}

}  // namespace sensing_and_control_unit
