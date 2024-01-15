#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Constructor called for a dog\n";
	this->type = "Dog";
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Copy constructor called for a dog\n";
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called for a dog\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "*OUAF OUAF make the Dog*\n";
}

Dog	&Dog::operator=(Dog const &rhs)
{
	std::cout << "Assignment operator called for a dog\n";
	this->type = rhs.type;

	return (*this);
}
