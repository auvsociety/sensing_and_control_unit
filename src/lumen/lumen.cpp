#include "lumen.hpp"

namespace sensing_and_control_unit {
Lumen::Lumen() {}
Lumen::~Lumen() {}

void Lumen::initialize() {
  lumen_.attach(kLumenPin);
  lumen_.write(0);
}

void Lumen::setBrightness(int brightness) { lumen_.write(brightness); }

void Lumen::turnOn() { lumen_.write(180); }

void Lumen::turnOff() { lumen_.write(0); }

}  // namespace sensing_and_control_unit
