#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Brain* brain;

		Cat(void);
		~Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		void makeSound(void) const;
};
