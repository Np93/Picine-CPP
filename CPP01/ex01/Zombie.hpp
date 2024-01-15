#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
private:
	std::string _name;

public:
	void	announce(void);
	void	set_name(std::string name_);

	Zombie();
	~Zombie();
};

Zombie*	zombieHorde( int N, std::string name);

#endif
