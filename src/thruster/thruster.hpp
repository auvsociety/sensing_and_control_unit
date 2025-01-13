#ifndef SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP

#include "thruster_info.hpp"
#include <Servo.h>
#include <std_msgs/Int32MultiArray.h>
#include <ros.h>
#include "Arduino.h"

namespace sensing_and_control_unit
{    
    class Thrusters
    {
    private:
        Servo thrusters_[kThrusterCount];
        ros::Subscriber<std_msgs::Int32MultiArray> pwm_sub_;  
        void pwmCallback(const std_msgs::Int32MultiArray &msg);  

    public:
        Thrusters();
        ~Thrusters();
        void initialize();  
        void setPWMs(int pwm_values[kThrusterCount]);
    };
} // namespace sensing_and_control_unit

#endif // SENSING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_HPP
