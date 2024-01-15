#include "Animal.hpp"

Animal::Animal(void): type("random animal")
{
	std::cout << "Constructor called for an animal\n";
}

Animal::Animal(Animal const &src)
{
	
	std::cout << "Copy constructor called for an animal\n";
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Destructor called for an animal\n";
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "*makes the sound of an animal*\n";
}

Animal	&Animal::operator=(Animal const &rhs)
{
	std::cout << "Assignment operator called for an animal\n";
	this->type = rhs.getType();

	return (*this);
}
