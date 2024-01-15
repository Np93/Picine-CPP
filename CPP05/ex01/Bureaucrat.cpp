#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _grade(150), _name("noname")
{
	std::cout << "Default constructor of Bureaucrat called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	try
	{
		if (grade > 150)
			throw GradeTooLowException();
		else if (grade < 1)
			throw GradeTooHighException();
		else
		{
			this->_grade = grade;
			std::cout << "A Bureaucrat " << name << " with a grade " << _grade << " has beed constructed\n";
		}
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "The grade of " << name << " is too high, we keeped grade 1\n";
		this->_grade = 1;
	}
	catch (GradeTooLowException &e)
	{
		std::cout << "The grade of " << name << " is too low, we keeped grade 150\n";
		this->_grade = 150;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has beed destroyed\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

void	Bureaucrat::Downgrade(void)
{
	std::cout << "Decrementing bureaucrat " << _name << "'s grade " << _grade << " by 1\n";
	try
	{
		if (this->_grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch (GradeTooLowException &e)
	{
		std::cout << "The grade of " << this->_name << " is already at bottom, no need to bully him\n";
	}
}

void	Bureaucrat::Upgrade(void)
{
	std::cout << "Incrementing bureaucrat " << _name << "'s grade " << _grade << " by 1\n";
	try
	{
		if (this->_grade - 1 < 1)
			throw GradeTooHighException();
	
		else
			this->_grade--;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "The grade of " << this->_name << " is already maxed, no promotion needed for the Boss\n";
	}
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		if (form.beSigned(*this))
		{
			std::cout << "Bureaucrat " << this->_name << " signed form \"" << form.getName() << "\"\n";
		}
		else
			throw Form::GradeTooLowException();
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't sign form \"" << form.getName() << "\" because his grade was too low\n";
	}
}

std::string	Bureaucrat::getName(void) const
{
	return(this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (out);
}

const char *Bureaucrat::GradeTooLowException::tooLow(void) const throw()
{
	return ("The grade of your Bureaucrat is too low\n");
}

const char *Bureaucrat::GradeTooHighException::tooHigh(void) const throw()
{
	return ("The grade of your Bureaucrat is too high\n");
}
