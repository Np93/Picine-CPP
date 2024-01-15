#include "Weapon.hpp"

Weapon::Weapon(std::string _weapon_name)
{
	weapon_ = _weapon_name;
}

Weapon::~Weapon()
{
}

std::string &Weapon::getType(void)
{
	return (this->weapon_);
}

void Weapon::setType(std::string _weapon_name)
{
	this->weapon_ = _weapon_name;
}
