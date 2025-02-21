#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Program requires one and only one argument to run properly"
			<< std::endl;
		std::cout << "Please try again..." << std::endl;
		return 0;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
