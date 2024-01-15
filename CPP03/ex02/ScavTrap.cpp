#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	this->setName(name);
	this->setHP(100);
	this->setEP(50);
	this->setAtt(20);

	std::cout << "Constructor called for ScavTrap " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Copy constructor called for ScavTrap " << this->getName() << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called for ScavTrap " << this->getName() << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getHP() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no more hit point\n";
		return ;
	}
	if (this->getEP() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no more energy point\n";
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAtt() << " points of damage\n";
	this->setEP( this->getEP() - 1 );
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << this->getName() << " entered in Gate keeper mode\n";
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	this->setName(rhs.getName());
	this->setHP(rhs.getHP());
	this->setEP(rhs.getEP());
	this->setAtt(rhs.getAtt());

	return (*this);
}
