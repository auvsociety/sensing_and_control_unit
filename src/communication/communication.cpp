#include "communication.hpp"
 namespace sensing_and_control_unit {
Communication::Communication(/* args */) {}
Communication::~Communication() {}
void Communication::initialize() {
    nh.initNode();
    calibrate_flag_sub = nh.subscribe<std_msgs::Bool>("/control/calibration", 10, &Communication::calibrate_flag_callback, this);
    pwm_flag_sub = nh.subscribe<std_msgs::Int32MultiArray>("/control/pwm", 10, &Communication::thruster_pwm_callback, this);
    lumen_brightness_sub = nh.subscribe<std_msgs::Int8>("/control/lumen", 10, &Communication::lumen_brightness_callback, this);
    led_indicator_sub = nh.subscribe<std_msgs::Int16>("/control/led", 10, &Communication::led_indicator_callback, this);


    // linear_acceleration_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/linear_acceleration", 10);
    // angular_velocity_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/angular_velocity", 10);
    
    orientation_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/orientation", 10);
    magnetic_field_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/magnetic_field", 10);
    depth_pub = nh.advertise<std_msgs::Float32>("/depth_data", 10);
    imu_pub = nh.advertise<geometry_msgs::Vector3>("/sensors/imu", 10);

}


void Communication::calibrate_flag_callback(const std_msgs::Bool &calib_msg){
    calibrate_flag_ = calib_msg.data;
}

void Communication::thruster_pwm_callback(const std_msgs::Int32MultiArray &thruster_msg){
    for (int i = 0; i < kThrusterCount; i++) 
    {
        pwm_values_[i] = thruster_msg.data[i];
    }
}

void Communication::lumen_brightness_callback(const std_msgs::Int8 &lumen_msg){
    lumen_brightness_ = lumen_msg.data;
}

void Communication::led_indicator_callback(const std_msgs::Int16 &led_msg){
    led_indicator_ = led_msg.data;
}
//all callback functions for the subscribers above


bool Communication::getCalibrateFlag(){ 
    return calibrate_flag_;
 } 

bool Communication::getDiagnosticsFlag(){
    return diagnostics_flag_;
 } 

bool Communication::getPWMFlag(){ 
    return pwm_flag_;
} 

bool Communication::getLumenFlag(){
     return lumen_brightness_>=1100;
} 

int Communication::getLedIndicator() {
     return led_indicator_; 
}

int Communication::getLumenBrightness(){
     return lumen_brightness_; 
}

int Communication::getPWMValues(int i) {
    if(i>=0 && i<kThrusterCount)
        return pwm_values_[i];
    else
        return 0;
}

void Communication::sendOrientation(Vec3f orientation){
    geometry_msgs::Vector3 orientation_msg;
    orientation_msg.x = orientation.x;
    orientation_msg.y = orientation.y;
    orientation_msg.z = orientation.z;
    orientation_pub.publish(&orientation_msg);
};

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
    magnetic_field_pub.publish(&magnetic_field_msg);
};
void Communication::sendDepth(float depth)
{
    std_msgs::Float32 depth_msg;
    depth_msg.data = depth;
    depth_pub.publish(&depth_msg);
};

// void Communication::logMessage(const char *message, ErrorLevel error_level){};

void Communication::receiveCommands()
{
    nh.spinOnce();
};

}  // namespace sensing_and_control_unit
