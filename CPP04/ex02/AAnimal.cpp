#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("random animal")
{
	this->type = "Aanimal";
	std::cout << "Constructor called for an animal\n";
}

AAnimal::AAnimal(AAnimal const &src)
{
	
	std::cout << "Copy constructor called for an animal\n";
	this->type = src.getType();
}

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor called for an animal\n";
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "*makes the sound of an animal*\n";
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "Assignment operator called for an animal\n";
	this->type = rhs.getType();

	return (*this);
}
