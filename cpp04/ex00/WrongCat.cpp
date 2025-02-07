#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other):
	WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return *this;
	WrongAnimal::operator=(other);
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound!" << std::endl;
}
