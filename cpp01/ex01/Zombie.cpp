#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Name constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie called " << name << " is destructed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}
