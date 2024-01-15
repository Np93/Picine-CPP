#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : Form("Default Robo", 72, 45)
{
	this->_target = "Default";
//	std::cout << "Robotomy Request" << *this << " has beed defaultly constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robo", 72, 45)
{
	this->_target = target;
	std::cout << "Robotomy Request" << *this << " has beed constructed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request" << *this << " has been destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form("Robo", 72, 45), _target(src._target)
{
	*this = src;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return(this->_target);
}

bool	RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		this->setSignature(true);
	return (this->isSigned());

}

bool	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (this->isSigned() == false)
			throw FormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExec())
			throw GradeTooLowException();
		int random = std::rand() % 2;
		std::cout << "Drill noise!!!\n";
		if (random == 0)
		{
			std::cout << "Congratulation ! " << this->_target << " has been robotomised with success\n";
		}
		else
		{
			std::cout << "Oh no ! We failed the robotomy of " << this->_target << std::endl;
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

const char	*RobotomyRequestForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the bureaucrat is too low to execute this Form\n");
}

const char	*RobotomyRequestForm::FormNotSignedException::what(void) const throw()
{
	return ("This Form isn't signed\n");
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &rhs)
{
	out << "Form name: " << rhs.getName()
		<< ", signed: " << ((rhs.isSigned()) ? "YES" : "NO")
		<< ", grade to sign: " << rhs.getGradeToSign()
		<< ", grade to execute: " << rhs.getGradeToExec()
		<< ", Target: " << rhs.getTarget();
	return (out);
}
