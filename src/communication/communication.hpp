#ifndef SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#include <Arduino.h>
#include <geometry_msgs/Vector3.h>
#include <ros.h>
#include <ros/console.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32MultiArray.h>

#include "error.hpp"
#include "mat3x3.hpp"
#include "thruster_info.hpp"
#include "vec3.hpp"

namespace sensing_and_control_unit {
class Communication {
 private:
  std_msgs::Int32MultiArray PWMValues;
  sensor_msgs::Imu accelerometer_gyroscope;
  sensor_msgs::MagneticField magnetometer_;
  sensor_msgs::Imu acceleration_angularvelocity;
  sensor_msgs::MagneticField magnetic_field_;
  geometry_msgs::Vector3 orientation_rpy;
  std_msgs::Int32MultiArray pwm_values;
  std_msgs::Float32 depth_raw;
  std_msgs::Float32 depth_data;
  ros::NodeHandle nh;
  ros::Publisher OrientationRPYPub;
  ros::Publisher accelerometerGyroscopeDataPub;
  ros::Publisher magnetometerDataPub;
  ros::Publisher accelerationAngularVelocityPub;
  ros::Publisher magneticFieldPub;
  ros::Publisher DepthRawDataPub;
  ros::Publisher DepthDataPub;

 public:
  Communication(/* args */);
  ~Communication();
  void initialize();

  Vec3f getAccelerometerOffsets();
  Vec3f getGyroscopeOffsets();
  Mat3x3f getMagnetometerSoftIronOffsets();
  Vec3f getMagnetometerHardIronOffsets();

  void PWMCallback(const std_msgs::Int32MultiArray& PWMValues);
  void sendOrientation(Vec3f orientation);
  void Communication::sendIMURawData(Vec3i accelerometer, Vec3i gyroscope,
                                     Vec3i magnetometer){};

  void Communication::sendIMUData(Vec3f acceleration, Vec3f angular_velocity,
                                  Vec3f magnetic_field){};
  void sendDepthRawData(float depth);
  void sendDepth(float depth);

  void logMessage(const char* message, ErrorLevel error_level);
  void recieveCommands();
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP