#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void)
{
	std::cout << "AMateria defualt constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type): type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other): type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this == &other)
		return *this;
	std::cout << "AMateria copy assignment operator called" << std::endl;
	return *this;
}

const std::string& AMateria::getType(void) const { return type; }

void AMateria::use(ICharacter& target)
{
	(void)target;
}
