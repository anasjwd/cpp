#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string _name): ClapTrap(_name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is dead!" << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "FragTrap " << name << " have no energy left!"
			<< std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing "
		<< attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void FragTrap::highFivesGuys(void)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " requests a high five" << std::endl;
}
