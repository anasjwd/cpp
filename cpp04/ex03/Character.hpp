#pragma once
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
	private:
		std::string name;
		AMateria* materias[4];
		Character(void);

	public:
		Character(std::string name);
		~Character(void);
		Character(const Character& other);
		Character& operator=(const Character& other);
		
		const std::string &getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
