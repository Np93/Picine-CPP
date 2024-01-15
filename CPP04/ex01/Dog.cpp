#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Constructor called for a dog\n";
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Copy constructor called for a dog\n";
	*this = src;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Destructor called for a dog\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "*OUAF OUAF make the Dog*\n";
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::setBrain(Brain *brain)
{
	this->_brain = brain;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	std::cout << "Assignment operator called for a dog\n";
	this->type = rhs.type;
	*(this->_brain) = *(rhs._brain);

	return (*this);
}

void Dog::compareTo(Dog const &dog) const
{
	std::cout << std::endl;
	std::cout << "Now look what Dogs have in brain\n";
	std::cout << std::endl;
	std::cout << "Dog brain";
	std::cout << "___________________";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->_brain)->getIdea(i)) << std::endl;
	std::cout << std::endl;
}
