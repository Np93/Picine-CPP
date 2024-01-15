#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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
		void compareTo(Dog const & other_dog) const;

		Dog	&operator=(Dog const &rhs);

};

#endif
