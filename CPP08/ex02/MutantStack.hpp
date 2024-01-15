#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef	T*	iterator;
		typedef	T const *	const_iterator;

		MutantStack() {};
		MutantStack(const MutantStack &src) {(void)src;};
		virtual ~MutantStack() {};

		MutantStack &operator=(MutantStack const &rhs)
		{
			(void)rhs;
			return (*this);
		};

		iterator begin()
		{
			std::vector<T>	v;
			T				top;
			iterator		ret;
			int				i = 0;
			while (!this->empty())// return si la pille est vide(empty)
			{
				top = this->top();//top renvoie une referance a l'element superieur
				v.push_back(top);
				this->pop();// pop enleve un elelemt en haut de la stack et taille = -1
				i++;
				
			}
			this->push(v[i - 1]);
			i--;
			ret = &(this->top());
			while (i--)
				this->push(v[i]);//ajoute un nouvelle element superieur
			return (ret);
		}

		iterator end() { return (&this->top() + 1); }	
};

#endif
