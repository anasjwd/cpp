#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("bob", 150);

	std::cout << b << std::endl;
	try {
		b.increment();
		b.decrement();
		b.decrement();
	}
	catch (std::exception& e) {
		std::cout << "Caught an exception: " << e.what() << std::endl;
		return 1;
	}
	std::cout << b << std::endl;
	return 0;
}
