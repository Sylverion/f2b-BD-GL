// vec3.h

#ifndef VEC3_H
#define VEC3_H

class Vec3 {
public:
    float x, y, z;

    Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }
};

#endif // VEC3_H