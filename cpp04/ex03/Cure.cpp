#include "Cure.hpp"
#include <iostream>
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	(void)other;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	(void)other;
	std::cout << "Cure copy assignment operator called" << std::endl;
	return *this;
}

AMateria* Cure::clone(void) const
{
	Cure *cure;

	cure = new Cure(*this);
	return cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
