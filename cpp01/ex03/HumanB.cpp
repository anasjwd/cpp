#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(void) {}

HumanB::HumanB(std::string _name) : name(_name)
{
	this->weapon = NULL;
}

HumanB::~HumanB(void) {}

void	HumanB::attack(void)
{
	if (this->weapon == NULL)
	{
		std::cout << name << " can't attack, he don't have a weapon"
			<< std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType()
		<< std::endl;
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}
