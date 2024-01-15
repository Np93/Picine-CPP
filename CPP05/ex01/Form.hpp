#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	private:
		const std::string	_name;
		const int		_grade_to_sign;
		const int		_grade_to_execute;
		bool			_signed;

	public:
		Form();
		Form(std::string name, int toSign, int toExec);
		Form(Form const &src);
		~Form();

		std::string		getName(void) const;
		bool			isSigned(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExec(void) const;

		bool	beSigned(const Bureaucrat &bureaucrat);

		Form	&operator=(Form const &rhs);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*tooHigh(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*tooLow(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Form const &rhs);

#endif
