#include "Complex.hpp"
#include "ostream"
#include <stdlib.h>     /* exit, EXIT_FAILURE */

void _assert(bool condition, const char* text) {
	if(!condition) {
		std::cout << text;
	}
}

template <typename T>
void _assert(T a, T b, const char* text) {
	if(b != a) {
		std::cout << text;
		std::cout << a << b << std::endl;
	}
}

int main() {
	Complex<float> z1(2.0f, 2.0f);
	Complex<float> z2(0.0f, 1.0f);

	
	_assert(Complex<float>(3.0f, 4.0f).length() == 5.0f, "length");

	_assert(z1/2.0f == Complex<float>(1.0f, 1.0f), "operator/T");
	//Arthmetic operators:
	_assert((z1 + z2) == Complex<float>(2.0f, 3.0f), "operator+");
	_assert((z1 - z2) == Complex<float>(2.0f, 1.0f), "operator-");
	_assert(z1*z2 == Complex<float>(-2.0f, 2.0f), "operator*");
	_assert(z2/z1, Complex<float>(0.25f, 0.25f), "operator/");

	std::cout << z1.length()*z1.length();
	z1 = z2;
	_assert(z1.x == 0.0f && z1.y == 1.0f, "operator=");
	std::cout << "End of tests" << std::endl;
	return 0;
}
