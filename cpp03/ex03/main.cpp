#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap test0;
	DiamondTrap test1("test1");
	std::cout << test0 << std::endl;
	std::cout << test1 << std::endl;
	test1.attack("test0");
	test1.takeDamage(50);
	test1.beRepaired(10);
	std::cout << test1 << std::endl;
	test1.takeDamage(60);
	test1.attack("test0");
	std::cout << test1 << std::endl;
	test0.highFivesGuys();
	test0.guardGate();
	test1.whoAmI();
	return 0;
}
