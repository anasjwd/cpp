#include "Character.hpp"
#include <iostream>

Character::Character(std::string name): name(name)
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete materias[i];
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character& other): name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materias[i] == NULL)
			materias[i] = NULL;
		else
			materias[i] = other.materias[i]->clone();
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
		delete materias[i];
	for (int i = 0; i < 4; i++)
	{
		if (other.materias[i] == NULL)
			materias[i] = NULL;
		else
			materias[i] = other.materias[i]->clone();
	}
	name = other.name;
	std::cout << "Character copy assignment operator called" << std::endl;
	return *this;
}

const std::string& Character::getName(void) const
{
	return name;
}

void Character::equip(AMateria *m)
{
	int idx = 0;

	while (materias[idx] != NULL && idx <= 3)
		idx++;
	if (idx > 3)
		return ;
	materias[idx] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid entry, try again!" << std::endl;
		return ;
	}
	materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid entry, try again!" << std::endl;
		return ;
	}
	if (materias[idx] == NULL)
		return ;
	materias[idx]->use(target);
}
