#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Constructor called for a cat\n";
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src)
{
	*this = src;
	std::cout << "Copy constructor called for a cat\n";
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Destructor called for a cat\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "*MIAOU MIAOU make the Cat*\n";
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::setBrain(Brain *brain)
{
	this->_brain = brain;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << "Assignment operator called for a cat\n";
	this->type = rhs.type;
	*(this->_brain) = *(rhs._brain);

	return (*this);
}

void Cat::compareTo(Cat const &cat) const
{
	std::cout << std::endl;
	std::cout << "Now look what cats have in brain\n";
	std::cout << std::endl;
	std::cout << "Cat brain";
	std::cout << "___________________";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->_brain)->getIdea(i)) << std::endl;
	std::cout << std::endl;
}
