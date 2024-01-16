#include "Contact.hpp"

std::string Contact::table_name[5] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->info[i] = std::string();
}

Contact::~Contact()
{
}

bool Contact::set_info(int index)
{
	this->index = index;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << Contact::table_name[i] << ":\n>";
		std::getline(std::cin, this->info[i]);
		if (!std::cin.good() || std::cin.eof())
			return (false);
	}
	size_t size = 0;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		size += this->info[i].length();
		if (size == 0)
		{
			std::cout << "an info on a contact is empty!" << std::endl;
			return (false);
		}
		size = 0;
	}	
	std::cout << "Contact added !" << std::endl;
	return (true);
}

void Contact::display_search()
{
	std::cout << "|" << std::setw(10) << this->index;
	for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->info[i].length() > 10)
			std::cout << this->info[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->info[i];
	}
	std::cout << "|" << std::endl;
}

void	Contact::display(void)
{
	std::cout << "all your contact information !" << std::endl;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << Contact::table_name[i] << ": ";
		std::cout << this->info[i] << std::endl;
	}
}