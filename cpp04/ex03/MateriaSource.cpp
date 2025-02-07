#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		knownMaterias[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		knownMaterias[i] = other.knownMaterias[i]->clone();
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
		delete knownMaterias[i];
	for (int i = 0; i < 4; i++)
		knownMaterias[i] = other.knownMaterias[i]->clone();
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete knownMaterias[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int idx = 0;

	while (knownMaterias[idx] != NULL)
		idx++;
	if (idx > 3)
	{
		std::cout << "Source's inventory is full" << std::endl;
		return ;
	}
	knownMaterias[idx] = m;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	int idx = 0;
	while (knownMaterias[idx] != NULL && idx < 4 && type != knownMaterias[idx]->getType())
		idx++;
	if (idx > 3)
	{
		std::cout << "Unkown type!" << std::endl;
		return (NULL);
	}
	return (knownMaterias[idx]->clone());
}
