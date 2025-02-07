#pragma once
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon		*weapon;

	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon &_weapon);
};
