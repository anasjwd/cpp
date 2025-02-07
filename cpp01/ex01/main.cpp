#include "Zombie.hpp"
#include <cstdlib>

Zombie	*zombieHorde(int N, std::string name);

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(3, "zombie");
	for (int idx = 0; idx < 3; idx++)
		horde[idx].announce();
	delete[] horde;
	return 0;
}
