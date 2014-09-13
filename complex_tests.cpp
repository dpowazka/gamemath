#include "Complex.hpp"
#include "ostream"
#include <stdlib.h>     /* exit, EXIT_FAILURE */

void _assert(bool condition, const char* text) {
	if(!condition) {
		std::cout << text;
		exit(1);
	}
}

int main() {
	Complex<float> z1(2.0f, 2.0f);
	Complex<float> z2(0.0f, 1.0f);

	_assert((z1 + z2) == Complex<float>(2.0f, 3.0f), "operator+");
	_assert((z1 - z2) == Complex<float>(2.0f, 1.0f), "operator-");

	std::cout << "End of tests" << std::endl;
	return 0;
}
