#include "Zombie.hpp"

Zombie::Zombie(void)
{}

Zombie::Zombie(std::string name) : name(name)
{}

Zombie::~Zombie(void)
{
	std::cout << name << ": destructed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}
