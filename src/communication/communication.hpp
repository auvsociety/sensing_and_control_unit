#ifndef SENSIING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#define SENSIING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#include "error.hpp"
#include "vec3.hpp"
#include "thruster_info.hpp"

namespace sensing_and_control_unit {
class Communication {
 private:
    bool calibrate_flag_ = false;
    bool diagnostics_flag_ = false;
    bool pwm_flag_ = false;
    int led_indicator_ = 0;
    int pwm_values_[kThrusterCount] = {0, 0, 0, 0, 0, 0};

 
 public:
  Communication(/* args */);
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
  void sendIMURawData(Vec3f accelerometer, Vec3f gyroscope, Vec3f magnetometer);
  void sendIMUData(Vec3f acceleration, Vec3f angular_velocity,
                   Vec3f magnetic_field);
  void sendDepthRawData(int depth);
  void sendDepth(float depth);

  void logMessage(const char *message, ErrorLevel error_level);
  void recieveCommands();
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
