#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): 
	ClapTrap(),
	FragTrap(),
	ScavTrap(),
	name("Default")
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30; 
	ClapTrap::name = "Default_clap_name";
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string _name):
	ClapTrap(_name + "_clap_name"),
	FragTrap(),
	ScavTrap(),
	name(_name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
	ClapTrap(other),
	FragTrap(other),
	ScavTrap(other),
	name(other.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	name = other.name;
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "ClapTrap name: " << ClapTrap::name << ", "
		<< "DiamondTrap name: " << name << std::endl;
}
