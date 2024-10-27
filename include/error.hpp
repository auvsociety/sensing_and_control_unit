#ifndef SENSING_AND_CONTROL_UNIT_SRC_ERROR_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_ERROR_HPP

namespace sensing_and_control_unit
{   
enum ErrorLevel
{
    INFO,
    WARNING,
    ERROR,
    FATAL
};
typedef enum ErrorLevel ErrorLevel;

} // namespace sensing_and_control_unit 
#endif // SENSING_AND_CONTROL_UNIT_SRC_ERROR_HPP