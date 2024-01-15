#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Brain	*getBrain(void) const;
		void	setBrain(Brain *brain);

		virtual void	makeSound(void) const ;
		void compareTo(Cat const &cat) const;

		Cat	&operator=(Cat const &rhs);

};

#endif
