#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Error: One and only one Input file must be present\n";
		return ( 1 );
	}
	try {
		BitcoinExchange btc;
		btc.calcBtcValues(av[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ( 1 );
	}
	return ( 0 );
}
