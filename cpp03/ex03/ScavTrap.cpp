#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " have no energy left!"
			<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
			<< attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void ScavTrap::guardGate(void)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is in Gate keeper mode." << std::endl;
}
