#ifndef SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP

#include "error.hpp"
#include "vec3.hpp"
#include "thruster_info.hpp"
#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int32MultiArray.h>
#include <geometry_msgs/Vector3.h>

namespace sensing_and_control_unit {

class Communication {
 private:
    ros::NodeHandle nh;

   ros::Subscriber<std_msgs::Bool> calibrate_flag_sub;
   ros::Subscriber<std_msgs::Int32MultiArray> pwm_flag_sub;  
   ros::Subscriber<std_msgs::Int8> lumen_brightness_sub; 
   ros::Subscriber<std_msgs::Int16> led_indicator_sub;

    ros::Publisher orientation_pub;
    ros::Publisher magnetic_field_pub;
    ros::Publisher depth_pub;
    ros::Publisher imu_pub;

    bool calibrate_flag_ = false;
    bool diagnostics_flag_ = false;
    bool pwm_flag_ = false;
    int led_indicator_ = 0;
    int pwm_values_[kThrusterCount] = {0,0,0,0,0,0};
    int lumen_brightness_ = 1100;

 public:
    Communication();
    ~Communication();
    void initialize();

    bool getCalibrateFlag();
    bool getDiagnosticsFlag();
    bool getPWMFlag();
    bool getLumenFlag();
    int getLedIndicator();
    int getPWMValues(int i);
    int getLumenBrightness();

    void sendOrientation(Vec3f orientation);
    void sendIMUData(Vec3f acceleration, Vec3f angular_velocity, Vec3f magnetic_field);
    void sendDepth(float depth);

    void receiveCommands();

    void calibrate_flag_callback(const std_msgs::Bool &calib_msg);
    void thruster_pwm_callback(const std_msgs::Int32MultiArray &thruster_msg);
    void lumen_brightness_callback(const std_msgs::Int8 &lumen_msg);
    void led_indicator_callback(const std_msgs::Int16 &led_msg);
};

}  // namespace sensing_and_control_unit

#endif // SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
