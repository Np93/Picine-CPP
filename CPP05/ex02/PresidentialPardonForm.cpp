#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("President", 25, 5)
{
	this->_target = "Default";
//	std::cout << "Presidential Pardon " << *this << " has beed defaultly constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("President Parent", 25, 5)
{
	this->_target = target;
	std::cout << "Presidential Pardon " << *this << " has beed constructed" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon " << *this << " has been destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form("PresidentialPardonForm", 25, 5), _target(src._target)
{
	*this = src;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

bool	PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		this->setSignature(true);
	return (this->isSigned());
}

bool	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (this->isSigned() == false)
			throw FormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExec())
			throw GradeTooLowException();
		else
		{
			std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox\n";
		}
		return (true);
	}
		catch (FormNotSignedException &e)
		{
			std::cout << e.what() << std::endl;
			return (false);
		}
		catch (GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
			return (false);
		}
	
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &rhs)
{
	out << "Form name: " << rhs.getName()
		<< ", signed: " << ((rhs.isSigned()) ? "YES" : "NO")
		<< ", grade to sign: " << rhs.getGradeToSign()
		<< ", grade to execute: " << rhs.getGradeToExec()
		<< ", Target: " << rhs.getTarget();
	return (out);
}

const char	*PresidentialPardonForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the bureaucrat is too low to execute this Form\n");
}

const char	*PresidentialPardonForm::FormNotSignedException::what(void) const throw()
{
	return ("This Form isn't signed\n");
}
