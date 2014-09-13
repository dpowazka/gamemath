#pragma once
#include <math.h> //hypot
#include <iostream>

template <typename T>
class Complex {
public:
	T x, y;
public:
	Complex(const T& px, const T& py) : x(px), y(py)
	{
	}

	Complex(const Complex &other) : x(other.x), y(other.y) 
	{
	}

	void operator=(const Complex &other) {
		this->x = other.x;
		this->y = other.y;
	}

	const T length() const {
		return (T)hypot(x, y);
	}

	const T dot_product(const Complex& other) const {
		return x*other.x + y*other.y;
	}

	const Complex<T> cast(const Complex &other) const {
		T length = dot_product(other);
		return normalized() * length;
	}

	const Complex<T> normalized() const {
		T l = length();
		return Complex(x / l, y / l);
	}

	const Complex<T> complement() const {
		return Complex(x, -y);
	}

	const Complex<T> operator-() const {
		return Complex(-x, -y);
	}

	const Complex<T> operator+(const Complex<T>& other) const {
		return Complex(x + other.x, y + other.y);
	}

	const Complex<T> operator-(const Complex<T>& other) const {
		return Complex(x - other.x, y - other.y);
	}

	const Complex<T> operator*(const Complex<T>& other) const {
		return Complex(x*other.x - y*other.y, x*other.y + y*other.x);
	}

	const Complex<T> operator*(const T& number) const {
		return Complex(x*number, y*number);
	}

	const Complex<T> operator/(const T& number) const {
		return Complex(x / number, y / number);
	}

	const Complex<T> operator/(const Complex<T>& other) const {
		return (*this) * other.complement()/ (other.length()*other.length());
	}

	void operator+=(const Complex<T>& other) const {
		this->x += other.x;
		this->y += other.y;
	}

	bool operator==(const Complex<T>& other) const {
		return this->x == other.x && this->y == other.y;
	}

	bool operator!=(const Complex<T>& other) const {
		return ! ((*this) == other);
	}
};

template <typename T, typename S>
const Complex<T> operator*(const S& number, const Complex<T>& complex) {
	return complex*number;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Complex<T> &c) {
	os << "(" << c.x << ", " << c.y << ")" << std::endl;
}
