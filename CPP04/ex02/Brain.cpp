#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor of Brain called\n";
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Genius";
}

Brain::Brain(Brain const &src)
{
	*this = src;
//	std::string *src_ideas = src.getIdea();
	std::cout << "Constructor of Brain called\n";
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain called\n";
	delete [] (this->_ideas);
}

std::string	Brain::getIdea(int n) const
{
	if (0 <= n && n <= 99)
		return (this->_ideas[n]);
	else
		std::cout << "Wrong index\n";
	return ("");
//	return (this->_ideas);
}
/*
void	Brain::setIdea(int n, std::string idea)
{
	if (0 <= n && n <= 99)
		this->_ideas[n] = idea;
	else
		std::cout << "Wrong index\n";
	return ;
}
*/
Brain	&Brain::operator=(Brain const &rhs)
{

	for (int i = 0; i <= 99; i++)
		this->_ideas[i] = rhs._ideas[i];

	return (*this);
}
