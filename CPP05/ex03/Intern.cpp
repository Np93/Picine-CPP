#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "An Intern has been constructed\n";
}

Intern::~Intern()
{
	std::cout << "An Intern has been destroyed\n";
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Form	*Intern::makeForm(std::string name, std::string target) const
{
	std::string	forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int 	i = 0;
	Form	*ret = NULL;
	try
	{
		while (i < 3)
		{
			if (name == forms[i])
				break ;
			i++;
		}
		switch (i)
		{
			case 0:
				ret = new ShrubberyCreationForm(target);
				return (ret);
			case 1:
				ret = new RobotomyRequestForm(target);
				return (ret);
			case 2:
				ret = new PresidentialPardonForm(target);
				return (ret);
			case 3:
				throw FormNameNotValidException();
				break ;
		}
		return (ret);
	}
	catch (FormNameNotValidException &e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
		return (NULL);
	};
}

const char	*Intern::FormNameNotValidException::what(void) const throw()
{
	return ("The form name is not valid");
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}
