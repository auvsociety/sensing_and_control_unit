#include "communication.hpp"

namespace sensing_and_control_unit {
Communication::Communication(/* args */) {}
Communication::~Communication() {}

void Communication::initialize() {}

bool Communication::getCalibrateFlag() { return bool(); }

bool Communication::getDiagnosticsFlag() { return bool(); }

bool Communication::getPWMFlag() { return bool(); }

bool Communication::getLumenFlag() { return bool(); }

int Communication::getLedIndicator() { return int(); }

int Communication::getLumenBrightness() { return int(); }

int Communication::getPWMValues(int i) { return int(); }

void Communication::sendOrientation(Vec3f orientation){};

void Communication::sendIMURawData(Vec3f accelerometer, Vec3f gyroscope,
                                   Vec3f magnetometer){};

void Communication::sendIMUData(Vec3f acceleration, Vec3f angular_velocity,
                                Vec3f magnetic_field){};

void Communication::sendDepthRawData(int depth){};

void Communication::sendDepth(float depth){};

void Communication::logMessage(const char *message, ErrorLevel error_level){};

void Communication::recieveCommands(){};

}  // namespace sensing_and_control_unit
