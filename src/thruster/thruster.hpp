#ifndef SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP
#include "thruster_info.hpp"
#include <Servo.h>
namespace sensing_and_control_unit
{    
    class Thrusters
    {
    private:
        Servo thrusters_[kThrusterCount];
    public:
        Thrusters();
        ~Thrusters();
        void initialize();
        void setPWMs(int pwm_values[kThrusterCount]);
    };
} // namespace sensing_and_control_unit
#endif // SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP