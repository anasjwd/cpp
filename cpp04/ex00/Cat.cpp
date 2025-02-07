#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) :
	Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	std::cout << "Cat copy assinment operator called" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}
