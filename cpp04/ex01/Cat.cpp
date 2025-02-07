#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) :
	Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	delete brain;
	Animal::operator=(other);
	brain = new Brain(*other.brain);
	std::cout << "Cat copy assinment operator called" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}
