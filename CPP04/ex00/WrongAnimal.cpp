#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("random WrongAnimal")
{
	std::cout << "Constructor called for a WrongAnimal\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "Copy constructor called for a WrongAnimal\n";
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor called for a WrongAnimal\n";
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*makes an WrongAnimal sound*\n";
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "Assignment operator called for a WrongAnimal\n";
	this->type = rhs.type;

	return (*this);
}
