#pragma once
#include <string>
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon		&weapon;
		std::string	name;
		HumanA(void);

	public:
		HumanA(std::string name, Weapon& weapon);
		HumanA(Weapon& weapon);
		~HumanA(void);
		void	attack(void);
};
