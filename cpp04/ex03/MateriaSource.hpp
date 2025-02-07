#pragma once
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria* knownMaterias[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource(void);

		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);
};
