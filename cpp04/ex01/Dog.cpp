#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	type = "Dog";
	brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other):
	Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return *this;
	delete brain;
	Animal::operator=(other);
	brain = new Brain(*other.brain);
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
}
