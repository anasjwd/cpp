#include "Zombie.hpp"
#include <cstdlib>

Zombie	*newZombie(std::string name)
{
	Zombie	*newZombie;

	try {
		newZombie = new	Zombie(name);
	}
	catch (std::bad_alloc &e) {
		std::cout << "Fatal: allocation failed" << std::endl;
		exit(1);
	}
	newZombie->announce();
	return (newZombie);
}
