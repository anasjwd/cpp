#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type)
{}

Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string value)
{
	type = value;
}
