#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);

		AMateria *clone(void) const;
		void use(ICharacter& target);
};
