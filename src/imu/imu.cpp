#include "imu.hpp"
 
Adafruit_HMC5883_Unified mag ;
Adafruit_MPU6050 mpu;
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
        Serial.println(" hmc Connection failed");
        delay(10);
    }
    Serial.println("hmc Connection successfull");
    calculateOffsets();
}


void Imu::update() {
    sensors_event_t a,g,m,t ;
    mpu.getEvent(&a, &g, &t);
    mag.getEvent(&m);
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
        accelerometer_offset_.x= accelerometer_offset_.x + acceleration_.x;
        accelerometer_offset_.y= accelerometer_offset_.y + acceleration_.y;
        accelerometer_offset_.z= accelerometer_offset_.z + acceleration_.z;
        gyroscope_offset_.x+= angular_velocity_.x;
        gyroscope_offset_.y+= angular_velocity_.y;
        gyroscope_offset_.z+= angular_velocity_.z;
    }
    accelerometer_offset_.x/=100;
    accelerometer_offset_.y/=100;
    accelerometer_offset_.z/=100;
    gyroscope_offset_.x/=100;
    gyroscope_offset_.y/=100;
    gyroscope_offset_.z/=100;
    accelerometer_offset_.z-=9.8;
    }


void Imu::calibrate() {
     acceleration_.x-=accelerometer_offset_.x;
      acceleration_.y-=accelerometer_offset_.y;
       acceleration_.z-=accelerometer_offset_.z;
     angular_velocity_.x-= gyroscope_offset_.x;
     angular_velocity_.y-= gyroscope_offset_.y;
     angular_velocity_.z-= gyroscope_offset_.z;
     magnetic_field_= (magnetic_field_ - magnetometer_hard_iron_offset_)*magnetometer_soft_iron_offset_;
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