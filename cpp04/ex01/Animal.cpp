#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return *this;
	type = other.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

void Animal::makeSound(void) const {}

std::string Animal::getType(void) const {
	return type;
}
