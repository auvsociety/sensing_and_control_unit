#include "imu.hpp"

namespace sensing_and_control_unit {
Imu::Imu() {}
Imu::~Imu() {}

void Imu::initialize(Communication& communication) {
    
    accelerometerOffsets = communication.accelerometerOffsets;
    gyroscopeOffsets = communication.gyroscopeOffsets;
    magnetometerHardIronOffsets = communication.magnetometerHardIronOffsets;
    magnetometerSoftIronOffsets = communication.magnetometerSoftIronOffsets;

    accelerometer_magnetometer_status = accelerometerMagnetometer.begin();
    gyroscope_status =  gyroscope.begin();
    gyroscope.setAccelerometerRange(ACCELERO_METER_RANGE_2);
    gyroscope.setGyroscopeRange(GYROSCOPE_RANGE_250);
    gyroscope.setSampleRateDivider(0);
    gyroscope.disableSleepMode();   

}

void Imu::update() {
    sensors_event_t accel_event,mag_event;
    accelerometerMagnetometer.getEvent(&accel_event,&mag_event);

    gyroscope.getSensorsReadings(raw_accelerometer_readings.y, raw_accelerometer_readings.x, raw_accelerometer_readings.z, raw_gyroscope_readings.y, raw_gyroscope_readings.x, raw_gyroscope_readings.z);
    raw_accelerometer_readings.y = -raw_accelerometer_readings.y;   // Data changed to match the orientation of both sensors in marty)
    raw_gyroscope_readings.y = -raw_accelerometer_readings.y;
    
    raw_magnetometer_readings = {mag_event.magnetic.x, mag_event.magnetic.y, mag_event.magnetic.z};
    
}

Vec3f Imu::getRawAccelerometerReading() { 
    return raw_accelerometer_readings; 
}

Vec3f Imu::getRawGyroscopeReading() { 
    return raw_gyroscope_readings;
}

Vec3f Imu::getRawMagnetometerReading() {
    return raw_magnetometer_readings; 
}

Vec3f Imu::getAcceleration() { 
    FusionVector accelerometer = {raw_accelerometer_readings.x, raw_accelerometer_readings.y, raw_accelerometer_readings.z};
    accelerometer = FusionCalibrationInertial(accelerometer, accelerometerMisalignment, accelerometerSensitivity, accelerometerOffsets);
    acceleration = {accelerometer.axis.x, accelerometer.axis.y, accelerometer.axis.z};
    return acceleration; 
}

Vec3f Imu::getAngularVelocity() { 
    FusionVector gyroscope = {raw_gyroscope_readings.x, raw_gyroscope_readings.y, raw_gyroscope_readings.z};
    gyroscope = FusionCalibrationInertial(gyroscope, gyroscopeMisalignment, gyroscopeSensitivity, gyroscopeOffsets);
    angular_velocity = {gyroscope.axis.x, gyroscope.axis.y, gyroscope.axis.z};
    return angular_velocity;
}

Vec3f Imu::getMagneticField() { 
    FusionVector magnetometer;
    magnetometer = FusionCalibrationMagnetic(magnetometer, magnetometerSoftIronOffsets, magnetometerHardIronOffsets);
    magnetic_field = {magnetometer.axis.x, magnetometer.axis.y, magnetometer.axis.z};
    return magnetic_field; 
}

}  // namespace sensing_and_control_unit

