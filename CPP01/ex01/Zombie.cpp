#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name_)
{
	_name = name_;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << _name << ": " << "die" << std::endl;
}
