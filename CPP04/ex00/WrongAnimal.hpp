#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(int const n);
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal(void);

		std::string		getType(void) const;
	
		void			makeSound(void) const;

		WrongAnimal	&operator=(WrongAnimal const &rhs);
};

#endif
