#include "ClapTrap.hpp"

int	main(void)
{
	std::string s1 = "David";
	std::string s2 = "Golliat";

	ClapTrap c1(s1);
	ClapTrap c2(s2);

	c1.attack(s2);
	c2.takeDamage(4);
	c2.beRepaired(3);
	c2.beRepaired(18);

	c2.attack(s1);
	c1.takeDamage(9);
	c2.attack(s1);
	c1.takeDamage(9);
	c2.attack(s1);

	c1.beRepaired(3);
	c1.beRepaired(64);
	return (0);
}
