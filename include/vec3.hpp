#ifndef SENSING_AND_CONTROL_UNIT_SRC_VEC3_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_VEC3_HPP
template <typename T>
struct Vec3
{
    T x;
    T y;
    T z;
};
typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;
#endif // SENSING_AND_CONTROL_UNIT_SRC_VEC3_HPP