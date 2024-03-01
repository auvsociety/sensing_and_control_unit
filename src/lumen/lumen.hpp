#ifndef SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP
#include "pins_info.hpp"
#include <Servo.h> 
class Lumen
{
private:
    Servo lumen_;
public:
    Lumen(/* args */);
    ~Lumen();
    void init();
    void setBrightness(int brightness);
    void turnOn();
    void turnOff();
};

Lumen::Lumen(/* args */)
{
}

Lumen::~Lumen()
{
}

#endif // SENSING_AND_CONTROL_UNIT_SRC_LUMEN_LUMEN_HPP