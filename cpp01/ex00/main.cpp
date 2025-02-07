#include "Zombie.hpp"
#include <cstdlib>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*Zoo;

	Zoo = newZombie("Zoo");
	randomChump("Zii");
	delete Zoo;
	return 0;
}
