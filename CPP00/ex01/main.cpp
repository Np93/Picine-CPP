#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	bool	start;
	std::string	text;

	phonebook.welcome();
	start = true;
	while(start)
	{
		std::cout << ">";
		std::getline(std::cin, text);
		if (text == "ADD")
			phonebook.add_contact();
		else if (text == "SEARCH")
			phonebook.search_contact();
		else if (text == "EXIT")
		{
			std::cout << "the file is corupted." << std::endl;
			std::cout << "Auto destruction on. Hasta la vista BABY" << std::endl;
			start = false;
		}
		if (!std::cin.good() || std::cin.eof())
		{
			std::cout << "Hey bro you break my ass by\n";
			return (0);
		}
	}
	return (0);
}
