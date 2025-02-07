#include <iostream>
#include "FragTrap.hpp"

int main(void)
{
	FragTrap test0;
	FragTrap test1("test1");
	FragTrap test2 = test1;
	FragTrap test3;

	std::cout << test0 << std::endl;
	std::cout << test1 << std::endl;
	test1.attack("test0");
	test1.takeDamage(10);
	test1.beRepaired(5);
	std::cout << test1 << std::endl;
	test1.takeDamage(100);
	test1.attack("test0");
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	test3 = test0;
	std::cout << test3 << std::endl;
	return 0;
}
