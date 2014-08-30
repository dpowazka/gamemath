#pragma once
#include <math.h> //hypot
#include <iostream>

//TODO: Write some tests.
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

	Complex normalized() const {
		T l = length();
		return Complex(x / l, y / l);
	}

	Complex complement() const {
		return Complex(x, -y);
	}

	Complex operator-() const {
		return Complex(-x, -y);
	}

	Complex operator+(const Complex& other) const {
		return Complex(x + other.x, y + other.y);
	}

	Complex operator-(const Complex& other) const {
		return Complex(x - other.x, y - other.y);
	}

	Complex operator*(const Complex& other) const {
		return Complex(x*other.x - y*other.y, x*other.y + y*other.x);
	}

	Complex operator*(const T& number) const {
		return Complex(x*number, y*number);
	}

	Complex operator/(const T& number) const {
		return Complex(x / number, y / number);
	}

	Complex operator/(const Complex& other) const {
		return (*this) * other.complement() / sqr(other.length());
	}

	void operator+=(const Complex& other) const {
		this->x += other.x;
		this->y += other.y;
	}

	bool operator==(const Complex& other) const {
		return this->x == other.x && this->y == other.y;
	}

	bool operator!=(const Complex& other) const {
		return ! ((*this) == other);
	}
};

template <typename T, typename S>
Complex<T> operator*(const S& number, const Complex<T>& complex) {
	return complex*number;
}

template <typename T>
void print(const Complex<T> &c) {
	std::cout << "(" << c.x << ", " << c.y << ")" << std::endl;
}
