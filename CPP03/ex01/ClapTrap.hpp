#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class ClapTrap
{
	protected:
		std::string	_name;

	private:
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_att;

	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		std::string	getName(void) const;
		unsigned int	getHP(void) const;
		unsigned int	getEP(void) const;
		unsigned int	getAtt(void) const;
		void		setName(std::string);
		void		setHP(unsigned int amount);
		void		setEP(unsigned int amount);
		void		setAtt(unsigned int amount);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		ClapTrap	&operator=(ClapTrap const &rhs);
};

#endif
