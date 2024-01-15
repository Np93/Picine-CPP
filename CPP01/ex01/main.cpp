#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int	count = 5;

	horde = zombieHorde(count, "Groot");
	for(int i = 0; i < count; i++)
		horde->announce();
	delete [] horde;
	return (0);	
}
