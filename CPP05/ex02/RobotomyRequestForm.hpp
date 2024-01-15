#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
	private :
		std::string	_target;

	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs);

		std::string	getTarget( void ) const;
//		void execute(Bureaucrat const & executor) const;
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

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &rhs);

#endif
