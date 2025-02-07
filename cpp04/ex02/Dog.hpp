#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Brain* brain;

		Dog(void);
		~Dog(void);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound(void) const;
};
