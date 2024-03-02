#include "orientation_filter.hpp"

namespace sensing_and_control_unit {
OrientationFilter::OrientationFilter() {}
OrientationFilter::~OrientationFilter() {}

void OrientationFilter::initialize(unsigned int sample_rate) {
    FusionOffsetInitialise(&offset, sample_rate);
    FusionAhrsInitialise(&ahrs);

    const FusionAhrsSettings settings = {
            .convention = FusionConventionNed,
            .gain = 0.5f,
            .gyroscopeRange = 250.0f, 
            .accelerationRejection = 20.0f,
            .magneticRejection = 20.0f,
            .recoveryTriggerPeriod = 3 * sample_rate, 
    };
    FusionAhrsSetSettings(&ahrs, &settings);
}

void OrientationFilter::update(Vec3f acceleration, Vec3f angular_velocity,Vec3f magnetic_field){
    FusionVector accelerometer = {acceleration.x, acceleration.y, acceleration.z};
    FusionVector gyroscope = {angular_velocity.x, angular_velocity.y, angular_velocity.z};
    FusionVector magnetometer = {magnetic_field.x, magnetic_field.y, magnetic_field.z};

    current_time=millis();
    delta_time=current_time-prev_time;
    prev_time = current_time;
    if (start)
    {
         start = !start;
         delta_time = 0;
    }
    FusionAhrsUpdate(&ahrs, gyroscope, accelerometer, magnetometer, delta_time);
    FusionEuler rotation = FusionQuaternionToEuler(FusionAhrsGetQuaternion(&ahrs));
    // FusionVector translation = FusionAhrsGetEarthAcceleration(&ahrs);
    orientation = {rotation.angle.roll, rotation.angle.pitch, rotation.angle.yaw};
}

Vec3f OrientationFilter::getEulerAngles() { 
    return orientation; 
}

}  // namespace sensing_and_control_unit