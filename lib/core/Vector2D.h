#pragma once
#include <iostream>

class Vector2D
{
public:
	int x;
	int y;

	Vector2D();
    Vector2D(int xy);
	Vector2D(int x, int y);
	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
	Vector2D& operator+=(const Vector2D& v);
	Vector2D& operator-=(const Vector2D& v);
	Vector2D& operator*=(const Vector2D& v);
	Vector2D& operator/=(const Vector2D& v);
	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
	int distanceTo(const Vector2D& v) const;
};