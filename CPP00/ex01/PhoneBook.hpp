#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	 Contact contacts[8];
	int	count;

public:
	PhoneBook();
	virtual ~PhoneBook();

	void	welcome(void);
	void	add_contact(void);
	void	search_contact(void);
	void	search_header(void);
};
#endif
