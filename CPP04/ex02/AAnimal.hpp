#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal(AAnimal const &src);
		virtual ~AAnimal() = 0;

		std::string getType(void) const;

		virtual void	makeSound(void) const = 0;

		AAnimal	&operator=(AAnimal const &rhs);
};

#endif
