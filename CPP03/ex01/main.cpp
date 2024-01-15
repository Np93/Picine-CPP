#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::string s1 = "Bonny";
	std::string s2 = "Clyde";

	ClapTrap claptrap(s1);
	ScavTrap scavtrap(s2);

	claptrap.attack(s2);
	scavtrap.takeDamage(0);
	scavtrap.beRepaired(18);
	scavtrap.attack(s1);
	claptrap.takeDamage(20);
	scavtrap.attack(s1);
	claptrap.takeDamage(20);
	scavtrap.attack(s1);
	claptrap.beRepaired(64);
	scavtrap.guardGate();
	scavtrap.attack(s1);
	scavtrap.takeDamage(100);
	scavtrap.takeDamage(1);
	scavtrap.attack(s2);
	scavtrap.beRepaired(200);
	
	return (0);
}
