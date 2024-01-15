#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		std::string	getTarget(void) const;

//		void	execute(Bureaucrat const &exec) const;
		virtual bool	beSigned(const Bureaucrat &bureaucrat);
		virtual bool	execute(const Bureaucrat &executor) const;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &rhs);

#endif
