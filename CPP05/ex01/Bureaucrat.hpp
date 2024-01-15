#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		int	_grade;
		std::string const	_name;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &src);

		std::string	getName(void) const;
		int	getGrade(void) const;

		void	Upgrade(void);
		void	Downgrade(void);
		void	signForm(Form &form);

		Bureaucrat	&operator=(Bureaucrat const &rhs);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *tooHigh(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *tooLow(void) const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif
