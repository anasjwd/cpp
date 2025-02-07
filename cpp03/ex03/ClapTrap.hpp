#pragma once
#include <string>

class ClapTrap {
	protected:
		std::string	name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
	
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap(void);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& claptrap);
