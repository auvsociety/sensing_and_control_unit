#ifndef SENSIING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_INFO_HPP
#define SENSIING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_INFO_HPP

/**
 * @file thruster_info.hpp
 * @brief Defines constants related to thruster configuration.
 */

/**
 * @brief Number of thrusters in the system.
 */

const int kThrusterCount = 7;

/**
 * @brief Initial PWM value for thrusters.
 * @details This constant represents the initial PWM value used when configuring
 * thrusters.
 */

const int32_t kInitThrusterPwm = 1474;

/**
 * @brief Minimum allowable PWM value for thrusters.
 * @details This constant represents the minimum allowable PWM value for
 * thrusters.
 */

const int32_t kMinPwmValue = 1100;

/**
 * @brief Maximum allowable PWM value for thrusters.
 * @details This constant represents the maximum allowable PWM value for
 * thrusters.
 */

const int32_t kMaxPwmValue = 1900;
#endif  // SENSIING_AND_CONTROL_UNIT_SRC_THRUSTER_THRUSTER_INFO_HPP
