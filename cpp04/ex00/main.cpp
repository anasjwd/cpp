#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const Animal animalCopy(*dog);
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << animalCopy.getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animalCopy.makeSound();
	meta->makeSound();
	delete meta;
	delete cat;
	delete dog;
	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();
	delete wrong;
	return 0;
}
