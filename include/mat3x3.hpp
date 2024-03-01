#ifndef SENSIING_AND_CONTROL_UNIT_SRC_MAT3X3_HPP
#define SENSIING_AND_CONTROL_UNIT_SRC_MAT3X3_HPP
template <typename T>
struct Mat3x3
{
    T m00, m01, m02;
    T m10, m11, m12;
    T m20, m21, m22;
};

void copyToMat3x3(float arr[3*3], Mat3x3<float>& mat)
{
    mat.m00 = arr[0];
    mat.m01 = arr[1];
    mat.m02 = arr[2];
    mat.m10 = arr[3];
    mat.m11 = arr[4];
    mat.m12 = arr[5];
    mat.m20 = arr[6];
    mat.m21 = arr[7];
    mat.m22 = arr[8];
}
typedef Mat3x3<float> Mat3x3f;
typedef Mat3x3<int> Mat3x3i;
#endif // SENSIING_AND_CONTROL_UNIT_SRC_MAT3X3_HPP