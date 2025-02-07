#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void): type("WrongUndefined")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	type = other.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
		return *this;
	type = other.type;
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound!" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return type;
}
