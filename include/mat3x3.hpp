#ifndef SENSIING_AND_CONTROL_UNIT_SRC_MAT3X3_HPP
#define SENSIING_AND_CONTROL_UNIT_SRC_MAT3X3_HPP
template <typename T>
struct Mat3x3
{
    T m00, m01, m02;
    T m10, m11, m12;
    T m20, m21, m22;
};

typedef Mat3x3<float> Mat3x3f;
typedef Mat3x3<int> Mat3x3i;
#endif // SENSIING_AND_CONTROL_UNIT_SRC_MAT3X3_HPP