#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Constructor called for a cat\n";
	this->type = "Cat";
}

Cat::Cat(Cat const &src) : Animal(src)
{
	*this = src;
	std::cout << "Copy constructor called for a cat\n";
}

Cat::~Cat(void)
{
	std::cout << "Destructor called for a cat\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "*MIAOU MIAOU make the Cat*\n";
}

Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << "Assignment operator called for a cat\n";
	this->type = rhs.type;

	return (*this);
}
