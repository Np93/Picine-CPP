#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::welcome(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|          Welcome to MY PhoneBook          |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "order available [ADD, SEARCH, EXIT]." << std::endl;
}

void	PhoneBook::add_contact(void)
{
	if (this->count == 8)
		std::cout << "the PhoneBook is full" << std::endl;
	else
	{
		if (this->contacts[this->count].set_info(this->count + 1))
			this->count++;
	}
}

void	PhoneBook::search_header(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->count; i++)
		this->contacts[i].display_search();
	std::cout << "|-------------------------------------------|" << std::endl;
}

void	PhoneBook::search_contact(void)
{
	int	index;

	if (this->count == 0)
	{
		std::cout << "no contact add!" << std::endl;
		return;
	}
	else
	{
		this->search_header();
		std::cout << "enter an Index or put 0 to quit" << std::endl;
		while (!(std::cin >> index) || (index < 0 || index > this->count))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Index is invalid" << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index == 0)
			return;
		else if (index > 0)
			this->contacts[index - 1].display();
	}
}
