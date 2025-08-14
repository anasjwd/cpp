#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error\n";
		return ( 1 );
	}

	try {
		RPN rpn(av[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error\n";
	}
	return ( 0 );
}
