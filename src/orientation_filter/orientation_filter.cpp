#include "orientation_filter.hpp"


namespace sensing_and_control_unit {
OrientationFilter::OrientationFilter(Vec3f acceleration, Vec3f angular_velocity, Vec3f magnetic_field) 
{}
OrientationFilter::~OrientationFilter() {}

void OrientationFilter::initialize() 
{

    //initializing algorithms, set settings.
    FusionOffsetInitialise(&offset, sample_rate);
    FusionAhrsInitialise(&ahrs);//algorithm that combines sensor data into orientation relative to earth

    const FusionAhrsSettings settings = {
            .convention = FusionConventionNwu, //nwu or enu or ned
            .gain = 0.5f, //influence of gyro wrt other sensors
            .gyroscopeRange = 2000.0f, //from datasheet
            .accelerationRejection = 10.0f, 
            .magneticRejection = 10.0f,
            .recoveryTriggerPeriod = 5 * sample_rate, 
    };

    FusionAhrsSetSettings(&ahrs, &settings); //to define ahrs algorithms
}

void OrientationFilter::update(Vec3f acceleration, Vec3f angular_velocity,Vec3f magnetic_field)
{
    FusionVector accel = {acceleration.x,acceleration.y,acceleration.z};
    FusionVector angular_vel = {angular_velocity.x,angular_velocity.y,angular_velocity.z};
    FusionVector mag_field = {magnetic_field.x,magnetic_field.y,magnetic_field.z};

    current_time=millis();
    delta_time=current_time-elapsed_time;
    elapsed_time=current_time;

    delta_time=delta_time/1000; //in seconds
            
    FusionAhrsUpdate(&ahrs,angular_vel,accel,mag_field,delta_time);//to update ahrs algorithm

    const FusionEuler euler= FusionQuaternionToEuler(FusionAhrsGetQuaternion(&ahrs));//to get roll,pitch,yaw(euler angles)
    orientation.x=euler.angle.roll;
    orientation.y=euler.angle.pitch;
    orientation.z=euler.angle.yaw;

    const FusionVector earth = FusionAhrsGetEarthAcceleration(&ahrs);//to get acceleration in global frame
    earth_accel.x=earth.axis.x;
    earth_accel.y=earth.axis.y;
    earth_accel.z=earth.axis.z;    
}

Vec3f OrientationFilter::getEulerAngles() 
{    
    return orientation;
}
}

  // namespace sensing_and_control_unit
