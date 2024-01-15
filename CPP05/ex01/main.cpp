#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n\n";

	Bureaucrat	Ben("Ben", 1);
	Bureaucrat	Random("Alex", 50);

	Form		Budget("Budget validation", 50, 151);
	Form		Mission("A secret mission", 0, 200);

	std::cout << Ben << std::endl;
	std::cout << Mission << std::endl;
	std::cout << "\n";

	Ben.signForm(Mission);
	Random.signForm(Mission);

	std::cout << Mission << std::endl;

	std::cout << "\n\n";

	Random.Downgrade();
	std::cout << Random << std::endl;
	std::cout << Budget << std::endl;
	
	std::cout << "\n";

	Random.signForm(Budget);
	std::cout << Budget << std::endl;
	std::cout << "\n";

	return (0);
}
