#include "thruster.hpp"

namespace sensing_and_control_unit {
Thrusters::Thrusters() {}

Thrusters::~Thrusters() {}

/**
 *
 * @brief Initializes the thrusters, sets initial PWM for idle state.
 *
 * This function attaches each thruster to its designated pin, sets PWM to kInitThrusterPwm (idle state),
 * Prepares thrusters for control without active propulsion.
 * 
 * @note Ensure that thrusters_[] and kThrusterPins[] are correctly configured.
 * 
 * @param None
 * @return None
 */

void Thrusters::initialize() {

    for(int thruster_index=0; thruster_index<kThrusterCount; thruster_index++) {
        thrusters_[thruster_index].attach(kThrusterPins[thruster_index]);
        thrusters_[thruster_index].writeMicroseconds(kInitThrusterPwm);
    }

}

/**
 * @brief Set thruster PWM values.
 *
 * This function updates the PWM values for each thruster based on the provided array.
 * 
 * @note Ensure that thrusters_[] is initialized and configured correctly.
 *
 * @param pwm_values An array of int32_t values holding PWM values for each thruster.
 *                   The array size should be kThrusterCount.
 *
 * @return None
 */

void Thrusters::setPWMs(const int32_t pwm_values[kThrusterCount]) {

    for(int thruster_index=0; thruster_index<kThrusterCount; thruster_index++){
        thrusters_[thruster_index].writeMicroseconds(pwm_values[thruster_index]);
    }

}  // namespace sensing_and_control_unit
