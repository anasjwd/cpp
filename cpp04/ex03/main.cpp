#include <iostream>

#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* me = new Character("me");
	AMateria* tmp1;
	AMateria* tmp2;

	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	Character* you = new Character(*me);
	you->use(0, *bob);

	delete tmp1;
	me->unequip(0);
	delete tmp2;
	me->unequip(1);

	delete you;
	delete bob;
	delete me;
	delete src;

	return 0;
}
