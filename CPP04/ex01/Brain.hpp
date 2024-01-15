#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	*_ideas;

	public:
		Brain();
		Brain(Brain const &src);
		~Brain();

		std::string	getIdea(int n) const;
//		void		setIdea(int n, std::string idea);

		Brain	&operator=(Brain const &rhs);

};

#endif
