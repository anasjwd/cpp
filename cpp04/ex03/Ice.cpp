#include "Ice.hpp"
#include <iostream>
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	(void)other;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	(void)other;
	std::cout << "Ice copy assignment operator called" << std::endl;
	return *this;
}

AMateria* Ice::clone(void) const
{
	Ice *ice;

	ice = new Ice(*this);
	return ice;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
}
