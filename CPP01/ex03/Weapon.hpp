#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
private:
	std::string	weapon_;

public:
	std::string & getType(void);
	void	setType(std::string _name);
	
	Weapon(std::string _name);
	~Weapon();
};

#endif
