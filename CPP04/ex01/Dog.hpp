#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		Brain	*getBrain(void) const;
		void	setBrain(Brain *brain);

		virtual void	makeSound(void) const;
		void compareTo(Dog const &dog) const;

		Dog	&operator=(Dog const &rhs);

};

#endif
