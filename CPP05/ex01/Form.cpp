#include "Form.hpp"

Form::Form() : _name("Default"), _grade_to_sign(150), _grade_to_execute(150), _signed(false)
{
	std::cout << "A default " << *this << " has been constructed" << std::endl;
}

Form::~Form()
{
	std::cout << *this << " has beed destroyed\n";
}

Form::Form(std::string name, int toSign, int toExec) : _name(name), _grade_to_sign( (1 <= toSign && toSign <= 150) ? toSign : ( (toSign < 1) ? 1 : 150) ), _grade_to_execute( (1 <= toExec && toExec <= 150) ? toExec : ( (toExec < 1) ? 1 : 150) )
{
	this->_signed = false;
	try
	{
		if (_grade_to_sign > 150 || _grade_to_execute > 150)
			throw GradeTooLowException();
		else if (_grade_to_sign < 1 || _grade_to_execute < 1)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "The grade to " << " Form \"" << name << "\" is too high. We keeped grade 1\n";
	}
	catch (GradeTooLowException &e)
	{
		std::cout << "The grade to " << " Form \"" << name << "\" is too low. We keeped grade 150\n";
	}
}

Form::Form(Form const &src) : _name(src.getName()), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExec()), _signed(src.isSigned())
{
	std::cout << *this << " has been constructed from a copy" << std::endl;
}

Form	&Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

unsigned int	Form::getGradeToExec(void) const
{
	return (this->_grade_to_execute);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

bool	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_grade_to_sign >= bureaucrat.getGrade())
		this->_signed = true;
	else
	{
		if (this->_signed == true)
			return (false);
	}
	return (this->_signed);
}

const char *Form::GradeTooHighException::tooHigh(void) const throw()
{
	return ("The grade is too high\n");
}

const char *Form::GradeTooLowException::tooLow(void) const throw()
{
	return ("The grade is too low\n");
}

std::ostream	&operator<<(std::ostream &out, Form const &rhs)
{
	if (rhs.isSigned())
		out << "Form name: " << rhs.getName() << ", signed: YES, grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExec();
	else
		out << "Form name: " << rhs.getName() << ", signed: NO, grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExec();
	return (out);
}
