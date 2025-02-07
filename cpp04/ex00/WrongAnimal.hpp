#pragma once
#include <string>

class WrongAnimal {
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);

		void makeSound(void) const;
		std::string getType(void) const;
};
