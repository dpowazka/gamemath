#pragma once
#include <math.h> //hypot
#include <iostream>

//TODO: Write some tests.

// Return types are not const because:
// http://stackoverflow.com/questions/8716330/purpose-of-returning-by-const-value

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

	T length() const {
		return (T)hypot(x, y);
	}

	T dot_product(const Complex& other) const {
		return x*other.x + y*other.y;
	}

	Complex<T> cast(const Complex &other) const {
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
		return (*this) * other.complement() / sqr(other.length());
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
void print(const Complex<T> &c) {
	std::cout << "(" << c.x << ", " << c.y << ")" << std::endl;
}
