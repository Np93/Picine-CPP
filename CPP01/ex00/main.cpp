#include "Zombie.hpp"

int	main()
{
	
	std::string name1;
	std::cout << "zombie name:" << std::endl;
	std::getline(std::cin, name1);
	randomChump(name1);
	return (0);
}
