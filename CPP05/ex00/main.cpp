#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\n";
	Bureaucrat	random;
	Bureaucrat	Fred("Fred", 1);
	Bureaucrat	Helon("Helon", 0);
	Bureaucrat	Bernard("Bernard", 151);
	Bureaucrat	Anonime("Anonime", 10);

	std::cout << Fred << std::endl;
	Fred.Downgrade();
	std::cout << Fred << std::endl;
	Fred.Upgrade();
	Fred.Upgrade();
	Anonime.Upgrade();
	Anonime.Downgrade();
	random.Downgrade();
	Bernard = Helon;

	std::cout << Fred << std::endl;
	std::cout << random << std::endl;
	std::cout << Bernard << std::endl;

	return (0);

}
