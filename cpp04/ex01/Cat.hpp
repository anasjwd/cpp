#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* brain;

	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		void makeSound(void) const;
};
