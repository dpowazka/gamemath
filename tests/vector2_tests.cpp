#include "Vector2.hpp"
#include "math.h"

const float  PI=3.14159265358979f;

void _assert(bool condition, const char* text) {
	std::cout << text;
	if(condition) {
		std::cout << "..pass" << std::endl;
	} else {
		std::cout << "..failed" << std::endl;
	}
}

template <typename T>
void _assert(T a, T b, const char* text) {
	std::cout << text;
	if(b != a) {
		std::cout << "..failed";
		std::cout << a << b << std::endl;
	} else {
		std::cout << "..pass" << std::endl; 
	}
	
}

bool about(Vector2 a, Vector2 b) {
	return (a - b).length() < 0.01;
}

int main() {
	printf("--- Vector2 tests ---\n");
	_assert(Vector2(Vector2(1,2)), Vector2(1,2), "copy constructor");
	_assert(Vector2(1,2) + Vector2(-1, 1), Vector2(0, 3), "operator+");
	_assert(Vector2(3,4).length(), 5.0f, "length");
	_assert(-Vector2(-1, 2), Vector2(1, -2), "operator-");

	{
		Vector2 v1(0, 0), v2(2,1);
		v1 = v2;
		_assert(v1, Vector2(2,1), "operator=");
	}

	{
		Vector2 v1(10.1f, -2.3f), v2(1,1);
		v1 += v2;
		_assert(v1, Vector2(11.1f, -1.3f), "operator+=");
	}

	{
		Vector2 v1(0, 0), v2(2,3);
		v1 -= v2;
		_assert(v1, Vector2(-2, -3), "operator-=");
	}

	_assert(2*Vector2(1,2), Vector2(2, 4), "operator* pre");
	_assert(Vector2(1,2) * 2, Vector2(2, 4), "operator* post");
	_assert(Vector2(2,10)/2, Vector2(1, 5), "operator/");
	_assert(Vector2(2, 0).normalized(), Vector2(1, 0), "normalized X");
	_assert(Vector2(0, 2).normalized(), Vector2(0, 1), "normalized Y");
	_assert(Vector2(3, 4).normalized(), Vector2(3/5.0f, 4/5.0f), "normalized XY");

	{
		Vector2 v1(0, 2), v2(2, 0), v3(3,4);
		v1.normalize();
		v2.normalize();
		v3.normalize();
		_assert(v1, Vector2(0, 1), "normalize Y");
		_assert(v2, Vector2(1, 0), "normalize X");
	}

	_assert((Vector2(1, 0).rotated(PI/2) - Vector2(0,1)).length() < 1.01f , "rotated 90");
	_assert((Vector2(1, 0).rotated(-PI/2) - Vector2(0,-1)).length() < 1.01f , "rotated -90");
	_assert(Vector2(1, 0).rotated(PI/4), Vector2(1,1).normalized(), "rotated 45");

	{
		Vector2 v1 = Vector2(2,1).rotated(Vector2(1,1), PI/2);
		Vector2 v2 = Vector2(2,1).rotated(Vector2(1,1), -PI/2);
		_assert(about(v1, Vector2(1,2)), "rotated (1,1) 90");
		_assert(about(v2, Vector2(1,0)), "rotated (1,1) -90");
	}
	
	{
		Vector2 v1(1, 0), v2(1, 0), v3(1, 0);
		v1.rotate(PI/2);
		v2.rotate(-PI/2);
		v3.rotate(PI/4);

		_assert((v1 - Vector2(0,1)).length() < 1.01f , "rotate 90");
		_assert((v2 - Vector2(0,-1)).length() < 1.01f , "rotate -90");
		_assert(v3, Vector2(1,1).normalized(), "rotate 45");
	}

	{
		Vector2 v1 = Vector2(2,1);
		Vector2 v2 = Vector2(2,1);
		v1.rotate(Vector2(1,1), PI/2);
		v2.rotate(Vector2(1,1), -PI/2);
		_assert(about(v1, Vector2(1,2)), "rotate (1,1) 90");
		_assert(about(v2, Vector2(1,0)), "rotate (1,1) -90");
	}

	{
		Vector2 v1(1, 1), v2(10, 0), v3(0, 1);
		_assert(v2.cast(v1), Vector2(1, 0), "cast on X");
		_assert(v3.cast(v1), Vector2(0, 1), "cast on Y");
		_assert(Vector2(1, 0).cast(Vector2(0,1)), Vector2(0,0), "cast 0");
	}

	{
		Vector2 v1(1, 0), v2(0, 1), v3(1,1);
		_assert(v1.dotProduct(v2), 0.0f, "dotProduct 0");
		_assert(v3.dotProduct(v1)/v3.length(), (float)sin(PI/4), "dotProduct 45");

	}

	

	return 0;
}