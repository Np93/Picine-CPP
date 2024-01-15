#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
private:
	std::string name_;
	Weapon &_weapon;

public:
	HumanA(std::string _name, Weapon &weapon);
	void attack(void);
	
	~HumanA();
};

#endif
