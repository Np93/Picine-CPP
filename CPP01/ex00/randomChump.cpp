#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	*another_one;

	another_one = newZombie(name);
	another_one->announce();
	delete another_one;
}
