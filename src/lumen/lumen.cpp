#include "lumen.hpp"

namespace sensing_and_control_unit {

Lumen::Lumen() {}
Lumen::~Lumen() {}

void Lumen::initialize()
{
     lumen_.attach(kLumenPin);   
    lumen_.writeMicroseconds(min_pwm);//off
}

// void Lumen::initialize(ros::NodeHandle &nh) {
//     lumen_.attach(kLumenPin);   
//     lumen_.writeMicroseconds(min_pwm);//off
// }

void Lumen::setBrightness(int brightness) {
    int pwm = map(brightness, 0, 100, min_pwm, max_pwm);   
    lumen_.writeMicroseconds(pwm);   
}

}  // namespace sensing_and_control_unit
