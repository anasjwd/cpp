#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap test0;
	ClapTrap test1("test1");

	std::cout << test0 << std::endl;
	std::cout << test1 << std::endl;
	test0.attack("test1");
	test0.takeDamage(5);
	test0.takeDamage(5);
	test0.beRepaired(2);
	std::cout << test0 << std::endl;
	return 0;
}
