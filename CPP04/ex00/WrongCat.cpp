#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Constructor called for a WrongCat\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "Copy constructor called for a WrongCat\n";
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor called for a WrongCat\n";
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*MIAOU MIAOU make the WrongCat*\n";
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	this->type = rhs.type;
	std::cout << "Copy assignment operator called for a WrongCat\n";

	return (*this);
}
