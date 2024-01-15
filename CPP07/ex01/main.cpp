#include "iter.hpp"

int	main()
{
	int	cook[5] = {1, 2, 3, 4, 5};
	char	chat[5] = "chat";
	float	rit[4] = {0.1f, 2.3f, 4.5f, 6.7f};
	std::string 	ficelle[5] = {"qui", "a vue", "le chat", "porter", "le string"};
	
	std::cout << "int\n";
	iter(cook, 5, random);
	std::cout << std::endl;
	
	std::cout << "char\n";
	iter(chat, 5, random);
	std::cout << std::endl;

	std::cout << "float\n";
	iter(rit, 4, random);
	std::cout << std::endl;
	
	std::cout << "string\n";
	iter(ficelle, 5, random);
	std::cout << std::endl;

	return (0);
}
