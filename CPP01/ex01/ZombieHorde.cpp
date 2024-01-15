#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "the number of zombies cannot be less than 1" << std::endl;
		return (NULL);
	}
	Zombie	*zombie_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie_horde[i].set_name(name);
	return (zombie_horde);
}
