#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

ClapTrap::ClapTrap(void): name("Default")
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string _name): name(_name)
{
	std::cout << "ClapTrap name Constructor called" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	name = other.getName();
	hitPoints = other.getHitPoints();
	energyPoints = other.getEnergyPoints();
	attackDamage = other.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
		<< attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << name << " is dead!" << std::endl;
		return ;
	}
	std::cout << name << " took damage, loosing " << amount
		<< " of hit points!" << std::endl;
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << name << " is dead!" << std::endl;
		return ;
	}
	else if (energyPoints == 0)
	{
		std::cout << name << " have no energy left!"
			<< std::endl;
		return ;
	}
	std::cout << name << " got repaired, gaining " << amount
		<< " of hit points!" << std::endl;
	hitPoints += amount;
	--energyPoints;
}

std::string ClapTrap::getName(void) const
{
	return name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return attackDamage;
}

std::ostream& operator<<(std::ostream& out, const ClapTrap& claptrap)
{
	out << "name: " << claptrap.getName() << ", "
		<< "hit points: " << claptrap.getHitPoints() << ", "
		<< "energy points: " << claptrap.getEnergyPoints() << ", "
		<<  "attack points: " << claptrap.getAttackDamage() << ".";
	return out;
}
