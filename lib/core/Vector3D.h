#ifndef ENGINEJ_VECTOR3D_H
#define ENGINEJ_VECTOR3D_H

#include <iostream>
#include "Vector2D.h"
#include <atomic>


class Vector3D {
public:
    std::atomic<float> x;
    std::atomic<float> y;
    std::atomic<float> z;

    Vector3D();
    Vector3D(float xyz);
    Vector3D(float x, float y, float z);
    friend Vector3D& operator+(Vector3D& v1, const Vector3D& v2);
    friend Vector3D& operator-(Vector3D& v1, const Vector3D& v2);
    friend Vector3D& operator*(Vector3D& v1, const Vector3D& v2);
    friend Vector3D& operator/(Vector3D& v1, const Vector3D& v2);
    Vector3D& operator+=(const Vector3D& v);
    Vector3D& operator-=(const Vector3D& v);
    Vector3D& operator*=(const Vector3D& v);
    Vector3D& operator/=(const Vector3D& v);
    friend std::ostream& operator<<(std::ostream& stream, const Vector3D& v);
    [[nodiscard]] double distanceTo(const Vector3D& v) const;
    [[nodiscard]] Vector2D to2D() const;
};


#endif //ENGINEJ_VECTOR3D_H
