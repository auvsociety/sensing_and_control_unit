#include "communication.hpp"

namespace sensing_and_control_unit {
Communication::Communication(/* args */) {}
Communication::~Communication() {}

void calibrate_flag_callback(const std_msgs::Bool &calib_msg) {
  calibrate_flag_ = calib_msg.data;
}

void thruster_pwm_callback(const std_msgs::Int32MultiArray &thruster_msg) {
    for (int i = 0; i < kThrusterCount; i++) {
        pwm_values_[i] = thruster_msg.data[i];
    }

}

void lumen_brightness_callback(const std_msgs::Int32 &lumen_msg) {
    lumen_brightness_ = lumen_msg.data;

}

void led_indicator_callback(const std_msgs::Int32 &led_msg) {
    led_indicator_ = led_msg.data;
}
//all callback functions for the subscribers above

void Communication::initialize() {
    nh.initNode();  
ros::Subscriber calibrate_flag_sub = nh.subscribe("/control/calibration ", 10, calibrate_flag_callback);
ros::Subscriber thruster_pwm_sub = nh.subscribe("/control/pwm ", 10, thruster_pwm_callback);
ros::Subscriber lumen_brightness_sub = nh.subscribe("/control/lumen", 10, lumen_brightness_callback);
ros::Subscriber led_indicator_sub = nh.subscribe("/control/led ", 10, led_indicator_callback);



ros::Publisher orientation_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/orientation", 10);
ros::Publisher linear_acceleration_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/linear_acceleration", 10);
ros::Publisher angular_velocity_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/angular_velocity", 10);
ros::Publisher magnetic_field_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/magnetic_field", 10);


ros::Publisher depth_pub = nh.advertise<std_msgs::Float32>("/depth_data", 10);
// ros::Publisher log_pub = nh.advertise<std_msgs::String>("/log", 10);
 
} 

bool Communication::getCalibrateFlag() { return calibrate_flag_; } 

bool Communication::getDiagnosticsFlag() { return diagnostics_flag_; }//CS will send diagnostics flag, for RGB LED

bool Communication::getPWMFlag() { return pwm_flag_; }//CS will send thruster PWM 

bool Communication::getLumenFlag() { return lumen_brightness_>=1100; }//CS will send lumen brightness from 1 to 100. map it to 1100 to 1900

int Communication::getLedIndicator() { return led_indicator_; }//CS will send RGB LED

int Communication::getLumenBrightness() { return lumen_brightness_; }//CS will send 0-100 brightness

int Communication::getPWMValues(int i) {
    if(i>=0 && i<kThrusterCount)
        return pwm_values_[i];
    else
        return 0;
}//Thruster PWM

void Communication::sendOrientation(Vec3f orientation){
    geometry_msgs::Vector3 orientation_msg;
    orientation_msg.x = orientation.x;
    orientation_msg.y = orientation.y;
    orientation_msg.z = orientation.z;
    orientation_pub.publish(&orientation_msg);
}//RPY

void Communication::sendIMUData(Vec3f acceleration, Vec3f angular_velocity,Vec3f magnetic_field)
{
    geometry_msgs::Vector3 acceleration_msg;
    acceleration_msg.x = acceleration.x;
    acceleration_msg.y = acceleration.y;
    acceleration_msg.z = acceleration.z;
    imu_pub.publish(&acceleration_msg);

    geometry_msgs::Vector3 angular_velocity_msg;
    angular_velocity_msg.x = angular_velocity.x;
    angular_velocity_msg.y = angular_velocity.y;
    angular_velocity_msg.z = angular_velocity.z;
    imu_pub.publish(&angular_velocity_msg);

    geometry_msgs::Vector3 magnetic_field_msg;
    magnetic_field_msg.x = magnetic_field.x;
    magnetic_field_msg.y = magnetic_field.y;
    magnetic_field_msg.z = magnetic_field.z;
    imu_pub.publish(&magnetic_field_msg);
}


void Communication::sendDepth(float depth)
{
    std_msgs::Float32 depth_msg;
    depth_msg.data = depth;
    depth_pub.publish(&depth_msg);
};

// void Communication::logMessage(const char *message, ErrorLevel error_level){};

void Communication::recieveCommands()
{
    nh.spinOnce();
};

}  // namespace sensing_and_control_unit
