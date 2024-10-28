#include "orientation_filter.hpp"


namespace sensing_and_control_unit {
OrientationFilter::OrientationFilter(Vec3f acceleration, Vec3f angular_velocity, Vec3f magnetic_field) 
{

}
OrientationFilter::~OrientationFilter() {}

void OrientationFilter::initialize() 
{
    acceleration=getAcceleration();
    angular_velocity=getAngularVelocity();
    magnetic_field=getMagneticField();

    //initializing algorithms, set settings.
    FusionOffsetInitialise(&offset, sample_rate);
    FusionAhrsInitialise(&ahrs);
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
    ax=acceleration.x;
    ay=acceleration.y;
    az=acceleration.z;
    gx=angular_velocity.x;
    gy=angular_velocity.y;
    gz=angular_velocity.z;
    mx=magnetic_field.x;
    my=magnetic_field.y;
    mz=magnetic_field.z;

    while(gx&&gy&&gz)
    {
        FusionVector acceleration = {ax,ay,az};
        FusionVector angular_velocity = {gx,gy,gz};
        FusionVector magnetic_field = {mx,my,mz};

        current_time=millis();
        delta_time=current_time-elapsed_time;
        elapsed_time=current_time;

        delta_time=delta_time/1000; //in seconds
            
        FusionAhrsUpdate(&ahrs,angular_velocity,acceleration,magnetic_field,delta_time);
    }
}

Vec3f OrientationFilter::getEulerAngles() 
{    
    const FusionEuler euler= FusionQuaternionToEuler(FusionAhrsGetQuaternion(&ahrs));
    
    orientation.x=euler.angle.roll;
    orientation.y=euler.angle.pitch;
    orientation.z=euler.angle.yaw;

    return orientation;
}
}

  // namespace sensing_and_control_unit
