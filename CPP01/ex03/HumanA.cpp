#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &weapon) : name_(_name), _weapon(weapon)
{
//	name_ = _name;
//	this->weapon_type = _weapon->getType();
}

void	HumanA::attack(void)
{
	std::cout << name_ << " attacks with his " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
}
