#pragma once 
#include <math.h> //hypot
#include <iostream>

class Vector2 {
public:
	float x, y;
public:
	Vector2(float px, float py) : x(px), y(py)
	{
	}

	Vector2(const Vector2 &other) : x(other.x), y(other.y) 
	{
	}

	void operator=(const Vector2 &other) {
		this->x = other.x;
		this->y = other.y;
	}

	float length() const {
		return hypot(x, y);
	}

	const Vector2 operator-() const {
		return Vector2(-x, -y);
	}

	const Vector2 operator+(const Vector2 &other) const {
		return Vector2(x + other.x, y + other.y);
	}

	const Vector2 operator-(const Vector2 &other) const {
		return Vector2(x - other.x, y - other.y);
	}

	void operator+=(const Vector2 &other) {
		this->x += other.x;
		this->y += other.y;
	}

	void operator-=(const Vector2 &other) {
		this->x -= other.x;
		this->y -= other.y;
	}

	bool operator==(const Vector2 &other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2 &other) const {
		return x != other.x || y != other.y;
	}

	const Vector2 operator*(float scale) const {
		return Vector2(scale*x, scale*y);
	}

	const Vector2 operator/(float scale) const {
		return Vector2(x/scale, y/scale);
	}


	const Vector2 normalized() const {
		float l = length();
		if(l != 0.0f) {
			return Vector2(x/l, y/l);
		} else {
			return Vector2(0.0f, 0.0f);
		}
	}

	void normalize() {
		float l = length();
		if(l != 0.0f) {
			this->x = x/l;
			this->y = y/l;
		}
	}

	float dotProduct(const Vector2 &other) const {
		return x*other.x + y*other.y;
	}

	const Vector2 cast(const Vector2 &other) const {
		if(other.x != 0 && other.y != 0) {
			float len = dotProduct(other)/length();
			return normalized() * len;
		} else {
			return Vector2(0, 0);
		}
	}

	void rotate(float radians) {
		float ox = cos(radians);
		float oy = sin(radians);
		float rx = x * ox - y * oy;
		float ry = x * oy + y * ox;
		this->x = rx;
		this->y = ry;
	}

	const Vector2 rotated(float radians) const {
		float ox = cos(radians);
		float oy = sin(radians);
		return Vector2(x*ox - y*oy, x*oy + y*ox);
	}

	void rotate(const Vector2 center, float radians) {
		*this -= center;
		this->rotate(radians);
		*this += center;
	}

	const Vector2 rotated(const Vector2 center, float radians) const {
		return (*this - center).rotated(radians) + center;
	}
};

const Vector2 operator*(float scale, const Vector2 &vector) {
	return Vector2(scale * vector.x, scale * vector.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2 v) {
	os << "(" << v.x << ", " << v.y << ")" << std::endl;
}
