#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
	name_ = _name;
}

void HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon_type_ = &_weapon.getType();
}

void HumanB::attack(void)
{
	if (this->weapon_type_)
		std::cout << name_ << " attacks with his " << *(this->weapon_type_) << std::endl;
	else
		std::cout << name_ << " tries to attack but has no weapon " << std::endl;
}

HumanB::~HumanB()
{
}
