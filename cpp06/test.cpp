#include <iostream>
#include <sstream>

int main(int ac, char **av)
{
	(void)ac;
	std::istringstream iss(av[1]);
	int result;
	float f = 2E-0;
	(void)f;
	iss >> result;
	if (iss.fail())
	{
		std::cout << "error\n";
		return 1;
	}
	std::cout << result << std::endl;
	return 0;
}
