#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D() :x(0),y(0)
{
}

Vector2D::Vector2D(float x, float y) :x(x),y(y)
{
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	return v1;
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	return v1;
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
	v1.x /= v2.x;
	v1.y /= v2.y;
	return v1;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v)
{
	stream << "(" << v.x << "," << v.y << ")";
	return stream;
}

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& v)
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& v)
{
	this->x *= v.x;
	this->y *= v.y;
	return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& v)
{
	this->x /= v.x;
	this->y /= v.y;
	return *this;
}

double Vector2D::distanceTo(const Vector2D& v) const
{
	return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2));
}









