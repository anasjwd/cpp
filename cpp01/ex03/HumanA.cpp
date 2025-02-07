#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(Weapon& _weapon) : weapon(_weapon)
{}

HumanA::HumanA(std::string _name, Weapon& _weapon): weapon(_weapon), name(_name)
{}

HumanA::~HumanA(void) {}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType()
		<< std::endl;
}
