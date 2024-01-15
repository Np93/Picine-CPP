#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default Shrub", 145, 137)
{
	this->_target = "Default";
//	std::cout << "Shrubbery Creation " << *this << " has beed defaultly constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrub", 145, 137)
{
	this->_target = target;
	std::cout << "Shrubbery Creation " << *this << " has beed constructed" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation " << *this << " has been destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form("ShrubberyCreationForm", 145, 137), _target(src._target)
{
	*this = src;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

bool	ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		this->setSignature(true);
	return (this->isSigned());
}

bool	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try
	{
		std::string	tree =
		"         &&& &&  & &&		\n"
		"      && &//&/|& ()|/ @, &&	\n"
		"      &//(/&/&||/& /_/)_&/_&	\n"
		"   &() &//&|()|/&// '%' & ()	\n"
		"  &_/_&&_/ |& |&&/&__%_/_& &&	\n"
		"&&   && & &| &| /& & % ()& /&&	\n"
		" ()&_---()&/&/|&&-&&--%---()~	\n"
		"     &&     /|||		\n"
		"             |||		\n"
		"             |||		\n"
		"             |||		\n"
		"       , -=-~  .-^- _		\n"
		"              `		\n";
		if (this->isSigned() == false)
			throw FormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExec())
			throw GradeTooLowException();
		else
		{
			std::ofstream	ofs(this->_target);
			if (!ofs.is_open())
			{
				std::cout << "Coulnd't open the output file" << std::endl;
				return (false);
			}
			ofs << tree;
			return (true);
		}
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

const char	*ShrubberyCreationForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the bureaucrat is too low to execute this Form\n");
}

const char	*ShrubberyCreationForm::FormNotSignedException::what(void) const throw()
{
	return ("This Form isn't signed\n");
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &rhs)
{
	out << "Form name: " << rhs.getName() 
		<< ", signed: " << ((rhs.isSigned()) ? "YES" : "NO")
		<< ", grade to sign: " << rhs.getGradeToSign()
		<< ", grade to execute: " << rhs.getGradeToExec()
		<< ", Target: " << rhs.getTarget();
	return (out);
}
