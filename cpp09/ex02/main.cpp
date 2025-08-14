#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac <= 1)
	{
		std::cout << "Provide the program with a set of number!\n";
		return ( 1 );
	}
	try {
		PmergeMe fj(&av[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
