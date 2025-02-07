#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other):
	Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
}
