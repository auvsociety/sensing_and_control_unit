#include "imu.hpp"

namespace sensing_and_control_unit {
Imu::Imu() {}
Imu::~Imu() {}


void Imu::initialize() {
    while(!mpu.begin())
    {
        Serial.println(" MPU Connection failed");
        delay(10);
    }
    Serial.println("MPU Connection successfull");
     while(!mag.begin())
    {
        Serial.println(" FXOS8700 Connection failed");
        delay(10);
    }
    Serial.println("FXOS8700 Connection successfull");
    calculateOffsets();
}


void Imu::update() {
    sensors_event_t a,g,t,m ;
    mpu.getEvent(&a, &g, &t);
    mag.getEvent(&t ,&m);
    acceleration_.x=a.acceleration.x;
    acceleration_.y=a.acceleration.y;
    acceleration_.z=a.acceleration.z;
    angular_velocity_.x=g.gyro.x;
    angular_velocity_.y=g.gyro.y;
    angular_velocity_.z=g.gyro.z;
    magnetic_field_.x=m.magnetic.x;
    magnetic_field_.y=m.magnetic.y;
    magnetic_field_.z=m.magnetic.z;
}

void Imu::calculateOffsets() {
    for(int i=0;i<100;i++)
    {
        update();
        accelerometer_offset_+= acceleration_;
        gyroscope_offset_+= angular_velocity_;
    }
    accelerometer_offset_/=100;
    gyroscope_offset_/=100;
    accelerometer_offset_.z-=9.8;
    }


void Imu::calibrate() {
     acceleration_-=accelerometer_offset_;
     angular_velocity_-= gyroscope_offset_;
    //  magnetic_field_= (magnetic_field-magnetometer_hard_iron_offset)*magnetometer_soft_iron_offset;
}

Vec3f Imu::getAcceleration() { 
    update();
    calibrate();
    return acceleration_; }

Vec3f Imu::getAngularVelocity() { 
    update();
    calibrate();
    return angular_velocity_; }

Vec3f Imu::getMagneticField() { 
    update();
    calibrate();
    return magnetic_field_; }

}