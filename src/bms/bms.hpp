#ifndef SENSIING_AND_CONTROL_UNIT_SRC_BMS_BMS_HPP
#define SENSIING_AND_CONTROL_UNIT_SRC_BMS_BMS_HPP

namespace sensing_and_control_unit
{
class BMS
{
private:
    float voltage_ = 0;
    float current_ = 0;
    float temperature_ = 0;    
    
public:
    BMS(/* args */);
    ~BMS();
    void initialize();
    void update();
    float getVoltage();
    float getCurrent();
    float getTemperature();
};
} // namespace sensing_and_control_unit

#endif // SENSIING_AND_CONTROL_UNIT_SRC_BMS_BMS_HPP