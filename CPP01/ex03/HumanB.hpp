#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name_;
	std::string *weapon_type_;

public:
	HumanB(std::string _name);
	void setWeapon(Weapon &_weapon);
	void attack(void);

	~HumanB();
};

#endif
