#include "communication.hpp"

namespace sensing_and_control_unit {

Communication::Communication(/* args */) {}
Communication::~Communication() {}
ros::Publisher accelerometerGyroscopeDataPub("accelerometer_gyroscope_data",
                                             &accelerometer_gyroscope);
ros::Publisher magnetometerDataPub("magnetometer_data", &magnetometer_);
ros::Publisher accelerationAngularVelocityPub("acceleration_angularVelocity",
                                              &acceleration_angularvelocity);
ros::Publisher magneticFieldPub("magneticField", &magnetic_field_);
ros::Publisher OrientationRPYPub("orientation_RPY", &orientation_rpy);
ros::Publisher DepthRawDataPub("depth_raw_data", &depth_raw);
ros::Publisher DepthDataPub("Depth", &depth_data);
ros::Subscriber<std_msgs::Int32MultiArray> PWMsub("pwm_values", &PWMCallback);

void Communication::initialize() {
  nh.initNode();
  nh.subscribe(PWMsub);
  nh.advertise(accelerometerGyroscopeDataPub);
  nh.advertise(magnetometerDataPub);
  nh.advertise(accelerationAngularVelocityPub);
  nh.advertise(magneticFieldPub);
  nh.advertise(OrientationRPYPub);
  nh.advertise(DepthRawDataPub);
  nh.advertise(DepthDataPub);
}

Vec3f Communication::getAccelerometerOffsets() {
  Vec3f accelerometer_offsets;
  if (nh.getParam("/sensing_and_control_unit/accelerometer_offsets/x",
                  accelerometer_offsets.x)) {
    nh.getParam("/sensing_and_control_unit/accelerometer_offsets/y",
                accelerometer_offsets.y);
    nh.getParam("/sensing_and_control_unit/accelerometer_offsets/z",
                accelerometer_offsets.z);
  } else {
    logMessage("Accelerometer offsets not found. Using default values.",
               ErrorLevel::INFO);
    accelerometer_offsets.x = 0.0;
    accelerometer_offsets.y = 0.0;
    accelerometer_offsets.z = 0.0;
  }
  return accelerometer_offsets;
}

Vec3f Communication::getGyroscopeOffsets() {
  Vec3f gyroscope_offsets;
  if (nh.getParam("/sensing_and_control_unit/gyroscope_offsets/x",
                  gyroscope_offsets.x)) {
    nh.getParam("/sensing_and_control_unit/gyroscope_offsets/y",
                gyroscope_offsets.y);
    nh.getParam("/sensing_and_control_unit/gyroscope_offsets/z",
                gyroscope_offsets.z);
  } else {
    logMessage("Gyroscope offsets not found. Using default values.",
               ErrorLevel::INFO);
    gyroscope_offsets.x = 0.0;
    gyroscope_offsets.y = 0.0;
    gyroscope_offsets.z = 0.0;
  }
  return gyroscope_offsets;
}

Mat3x3f Communication::getMagnetometerSoftIronOffsets() {
  Mat3x3f magnetometer_softiron_offsets;
  float array[9];
  if (nh.getParam("/sensing_and_control_unit/magnetometer_softiron_offsets",
                  array)) {
    copyToMat3x3(array, magnetometer_softiron_offsets);
  } else {
    logMessage("Magnetometer softiron offsets not found. Using default values.",
               ErrorLevel::INFO);
    for (int array_index = 0; array_index < 9; array_index++) {
      array[index] = 0.0f;
      copyToMat3x3(array, magnetometer_softiron_offsets);
    }
  }

  return magnetometer_softiron_offsets;
}

Vec3f Communication::getMagnetometerHardIronOffsets() {
  Vec3f magentometer_hardiron_offsets;
  if (nh.getParam("/sensing_and_control_unit/magnetometer_hardiron_offsets/x",
                  magnetometer_hardiron_offsets.x)) {
    nh.getParam("/sensing_and_control_unit/magnetometer_hardiron_offsets/y",
                magnetometer_hardiron_offsets.y);
    nh.getParam("/sensing_and_control_unit/magnetometer_hardiron_offsets/z",
                magnetometer_hardiron_offsets.z);
  } else {
    logMessage("Magnetometer hardiron offsets not found. Using default values.",
               ErrorLevel::INFO);
    magentometer_hardiron_offsets.x = 0.0;
    magentometer_hardiron_offsets.y = 0.0;
    magentometer_hardiron_offsets.z = 0.0;
  }
  return magnetometer_hardiron_offsets;
}

void PWMCallback(const std_msgs::Int32MultiArray &PWMValues) {
  int32_t pwm_values[kThrusterCount];
  for (int thruster_index = 0; thruster_index < kThrusterCount;
       thruster_index++) {
    pwm_values[thruster_index] = PWMValues.data[thruster_index];
  }
}

void Communication::sendOrientation(Vec3f orientation) {
  orientation_rpy.x = orientation.x;
  orientation_rpy.y = orientation.y;
  orientation_rpy.z = orientation.z;
  OrientationRPYPub.publish(&orientation_rpy);
}

void Communication::sendIMURawData(Vec3f accelerometer, Vec3f gyroscope,
                                   Vec3f magnetometer) {
  accelerometer_gyroscope.linear_acceleration.x = accelerometer.x;
  accelerometer_gyroscope.linear_acceleration.y = accelerometer.y;
  accelerometer_gyroscope.linear_acceleration.z = accelerometer.z;
  accelerometer_gyroscope.angular_velocity.x = gyroscope.x;
  accelerometer_gyroscope.angular_velocity.y = gyroscope.y;
  accelerometer_gyroscope.angular_velocity.z = gyroscope.z;
  magnetometer_.magnetic_field.x = magnetometer.x;
  magnetometer_.magnetic_field.y = magnetometer.y;
  magnetometer_.magnetic_field.z = magnetometer.z;
  accelerometerGyroscopeDataPub.publish(&accelerometer_gyroscope);
  magnetometerDataPub.publish(&magnetometer_);
}

void Communication::sendIMUData(Vec3f acceleration, Vec3f angular_velocity,
                                Vec3f magnetic_field) {
  acceleration_angularvelocity.linear_acceleration.x = acceleration.x;
  acceleration_angularvelocity.linear_acceleration.y = acceleration.y;
  acceleration_angularvelocity.linear_acceleration.z = acceleration.z;
  acceleration_angularvelocity.angular_velocity.x = angular_velocity.x;
  acceleration_angularvelocity.angular_velocity.y = angular_velocity.y;
  acceleration_angularvelocity.angular_velocity.z = angular_velocity.z;
  magnetic_field_.magnetic_field.x = magnetic_field.x;
  magnetic_field_.magnetic_field.y = magnetic_field.y;
  magnetic_field_.magnetic_field.z = magnetic_field.z;
  accelerationAngularVelocityPub.publish(&acceleration_angularvelocity);
  magneticFieldPub.publish(&magnetic_field_);
}

void Communication::sendDepthRawData(float depth) {
  depth_raw.data = depth;
  DepthRawDataPub.publish(&depth_raw);
}

void Communication::sendDepth(float depth) {
  depth_data.data = depth;
  DepthDataPub.publish(&depth_data);
}

void Communication::logMessage(const char *message, ErrorLevel error_level) {
  switch (error_level) {
    case INFO:
      ROS_INFO("%s", message);
      break;
    case WARN:
      ROS_WARN("%s", message);
      break;

    case ERROR:
      ROS_ERROR("%s", message);
      break;

    case FATAL:
      ROS_FATAL("%s", message);
      break;

    default:
      ROS_WARN("Unknowm error level : %d", error_level);
      break;
  };
};

void Communication::recieveCommands() { nh.spinOnce(); }
}  // namespace sensing_and_control_unit
