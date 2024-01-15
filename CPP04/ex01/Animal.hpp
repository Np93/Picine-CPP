#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);

		std::string		getType(void) const;

		virtual void	makeSound(void) const;

		Animal	&operator=(Animal const &rhs);
};

#endif
