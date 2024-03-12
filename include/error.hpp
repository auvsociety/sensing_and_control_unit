#ifndef SENSING_AND_CONTROL_UNIT_SRC_ERROR_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_ERROR_HPP
namespace sensing_and_control_unit {

/**
 * @file error.hpp
 * @brief Defines error levels for the sensing and control unit.
 */
enum class ErrorLevel { INFO, WARNING, ERROR, FATAL };
}  // namespace sensing_and_control_unit
typedef enum ErrorLevel ErrorLevel;
#endif  // SENSING_AND_CONTROL_UNIT_SRC_ERROR_HPP