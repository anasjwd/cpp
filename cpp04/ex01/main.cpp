#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* animals[4];
	animals[0] = new Cat;
	animals[1] = new Cat;
	animals[2] = new Dog;
	animals[3] = new Dog;

	*animals[2] = *animals[3];
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
