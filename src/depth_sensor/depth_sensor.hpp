#ifndef SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP
class DepthSensor
{
private:
    /* data */
public:
    DepthSensor(/* args */);
    ~DepthSensor();
    void initialize();
    void getRawReading();
    void getDepth();
};

DepthSensor::DepthSensor(/* args */)
{
}

DepthSensor::~DepthSensor()
{
}

#endif // SENSING_AND_CONTROL_UNIT_SRC_DEPTH_SENSOR_DEPTH_SENSOR_HPP