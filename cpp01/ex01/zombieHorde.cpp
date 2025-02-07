#include "Zombie.hpp"
#include <cstdlib>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombieHorde;

	if (N < 1)
	{
		std::cout << "Failed: A zombie horde can't contain less than one zombie"
			<< ", NULL is returned." << std::endl;
		return (NULL);
	}
	try {
		zombieHorde = new Zombie[N];
	}
	catch (std::bad_alloc &e) {
		std::cout << "Fatal: allocation failed" << std::endl;
		exit(1);
	}
	for (int idx = 0; idx < N; idx++)
		new(zombieHorde + idx) Zombie(name);
	return (zombieHorde);
}
