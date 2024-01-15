#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "unistd.h"

int main()
{
	std::cout << "\n\n";

	Bureaucrat	Bill("Bill", 1);
	Bureaucrat	Fred("Fred", 150);

	ShrubberyCreationForm	Arbres("tree");
	RobotomyRequestForm		robot("Jean");
	PresidentialPardonForm	pres("Joe dalton");

	Bill.signForm(Arbres);
	Bill.executeForm(Arbres);
	Fred.signForm(Arbres);
	Fred.executeForm(Arbres);
	
	std::cout << "\n";
	Bill.signForm(robot);
	std::cout << "\n";
	
	for (int i = 0; i < 10; i++)
	{
		sleep(1);
		Bill.executeForm(robot);
	}

	Bill.signForm(pres);
	Bill.executeForm(pres);

	std::cout << "\n\n";

	std::cout << Bill << std::endl;
	std::cout << Fred << std::endl;
	std::cout << Arbres << std::endl;

	return (0);
}
