#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

class Intern
{

	private:

	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern	&operator=(Intern const &rhs);

		Form	*makeForm(std::string name, std::string target) const;

		class FormNameNotValidException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

#endif
