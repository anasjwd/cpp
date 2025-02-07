#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string _name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap(void);
		void attack(const std::string& name);
		void whoAmI(void);
};
