#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap test0;
	ScavTrap test1("test1");

	std::cout << test0 << std::endl;
	std::cout << test1 << std::endl;
	test1.attack("test0");
	test1.takeDamage(10);
	test1.takeDamage(10);
	test1.beRepaired(2);
	std::cout << test1 << std::endl;
	test1.guardGate();
	return 0;
}
