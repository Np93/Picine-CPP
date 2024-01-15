#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	int					index;
	static std::string	table_name[5];
	std::string			info[5];

	enum table {
		FirstName = 0,
		LastName,
		Nickname,
		PhoneNumber,
		DarkestSecret
	};
public:
	Contact();
	virtual ~Contact();

	bool	set_info(int index);
	void	display_search(void);
	void	display(void);
};

#endif
