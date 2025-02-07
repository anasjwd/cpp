#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = "idea";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void)
{
	delete[] ideas;
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this == &other)
		return *this;
	delete[] ideas;
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}
