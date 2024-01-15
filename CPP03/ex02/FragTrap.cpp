#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setName(name);
	this->setHP(100);
	this->setEP(100);
	this->setAtt(30);

	std::cout << "Constructor called for FragTrap " << this->getName() << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Copy constructor called for FragTrap " << this->getName() << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called for FragTrap " << this->getName() << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->getName() << " wants to high fives... any volounteer ?\n";
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	this->setName(rhs.getName());
	this->setHP(rhs.getHP());
	this->setEP(rhs.getEP());
	this->setAtt(rhs.getAtt());

	return (*this);
}
