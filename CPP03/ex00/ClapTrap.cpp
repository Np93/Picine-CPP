#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("NoName"), _hp(10), _ep(10), _att(0)
{
	std::cout << "Constructor called for ClapTrap " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _att(0)
{
	std::cout << "Constructor called for ClapTrap " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "Copy constructor called for ClapTrap " << this->_name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for ClapTrap " << this->_name << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHP(void) const
{
	return (this->_hp);
}

unsigned int	ClapTrap::getEP(void) const
{
	return (this->_ep);
}

unsigned int	ClapTrap::getAtt(void) const
{
	return (this->_att);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHP(unsigned int amount)
{
	this->_hp = amount;
}

void	ClapTrap::setEP(unsigned int amount)
{
	this->_ep = amount;
}

void	ClapTrap::setAtt(unsigned int amount)
{
	this->_att = amount;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hp == 0)
	{	
		std::cout << "ClapTrap " << this->_name << " has no more hit point\n";
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more energy point\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_att << " points of damage\n";
	this->_ep--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << this->_name << " is already dead\n";
		return ;
	}
	if (amount >= this->_hp)
	{
		std::cout << this->_name << " took " << this->_hp << " points of damage, he's now K.O.\n";
		this->_hp = 0;
	}
	else
	{
		this->_hp -= amount;
		std::cout << this->_name << " took " << amount << " points of damage, he has " << this->_hp << " hp left\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << this->_name << " has no more hit point\n";
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << this->_name << " has no more energy point\n";
		return ;
	}
	this->_ep -= 1;
	this->_hp += amount;
	std::cout << this->_name << " healed " << amount << " hp and now has " << this->_hp << " hp left\n";
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs.getName();
	this->_hp = rhs.getHP();
	this->_ep = rhs.getEP();
	this->_att = rhs.getAtt();

	return (*this);
}
