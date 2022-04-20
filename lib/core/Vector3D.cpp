#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D() :x(0),y(0),z(0)
{
}

Vector3D::Vector3D(float xyz) :x(xyz),y(xyz),z(xyz)
{
}

Vector3D::Vector3D(float x, float y, float z) :x(x),y(y),z(z)
{
}

Vector3D& operator+(Vector3D& v1, const Vector3D& v2)
{
    return *new Vector3D(
            v1.x + v2.x,
            v1.y + v2.y,
            v1.z + v2.z);
}

Vector3D& operator-(Vector3D& v1, const Vector3D& v2)
{
    return *new Vector3D(
            v1.x - v2.x,
            v1.y - v2.y,
            v1.z - v2.z);
}

Vector3D& operator*(Vector3D& v1, const Vector3D& v2)
{
    return *new Vector3D(
            v1.x * v2.x,
            v1.y * v2.y,
            v1.z * v2.z);
}

Vector3D& operator/(Vector3D& v1, const Vector3D& v2)
{
    return *new Vector3D(
            v1.x / v2.x,
            v1.y / v2.y,
            v1.z / v2.z);
}

std::ostream& operator<<(std::ostream& stream, const Vector3D& v)
{
    stream << "(" << v.x << "," << v.y << "," << v.z << ")";
    return stream;
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
    this->x.store(this->x + v.x) ;
    this->y.store(this->y + v.y) ;
    this->z.store(this->z + v.z) ;
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& v)
{
    this->x.store(this->x - v.x) ;
    this->y.store(this->y - v.y) ;
    this->z.store(this->z - v.z) ;
    return *this;
}

Vector3D& Vector3D::operator*=(const Vector3D& v)
{
    this->x.store(this->x * v.x) ;
    this->y.store(this->y * v.y) ;
    this->z.store(this->z * v.z) ;
    return *this;
}

Vector3D& Vector3D::operator/=(const Vector3D& v)
{
    this->x.store(this->x / v.x) ;
    this->y.store(this->y / v.y) ;
    this->z.store(this->z / v.z) ;
    return *this;
}

double Vector3D::distanceTo(const Vector3D& v) const
{
    return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2) + pow(v.z - z, 2));
}

Vector2D Vector3D::to2D() const {
    #define INCLINATION 2.f
    float x05 = 0.5f * x;
    float y05 = 0.5f * y;
    return {INCLINATION * x05 + INCLINATION * y05, x05 - y05 - z};
}
