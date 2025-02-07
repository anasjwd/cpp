#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal* cat = new Cat;
	const Animal* dog = new Dog;

	delete cat;
	delete dog;
	return 0;
}
