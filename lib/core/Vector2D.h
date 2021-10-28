#pragma once
#include <iostream>

/// class representing two-dimensional integer vector
class Vector2D
{
public:
	///dimension x of vector
	float x;
	///dimension y of vector
	float y;

	Vector2D();
	Vector2D(float x, float y);
	/// operator overload adding + functionality to object
	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	/// operator overload adding - functionality to object
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	/// operator overload adding * functionality to object
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	/// operator overload adding / functionality to object
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
	/// operator overload adding += functionality to object
	Vector2D& operator+=(const Vector2D& v);
	/// operator overload adding -= functionality to object
	Vector2D& operator-=(const Vector2D& v);
	/// operator overload adding *= functionality to object
	Vector2D& operator*=(const Vector2D& v);
	/// operator overload adding /= functionality to object
	Vector2D& operator/=(const Vector2D& v);
	/// operator overload adding outputing to stream to object
	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
	/// function calculating distance to another point in 2D space
	/// @param v vector representing other point in 2D space
	/// @return distance from this vector to vector v
	double distanceTo(const Vector2D& v) const;
};