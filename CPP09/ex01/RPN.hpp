#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>

class RPN 
{
	public:
		RPN();
		RPN(RPN const &src);
		~RPN();

		void	Math(char *av);

		RPN &operator=(RPN const &rhs);

	private:
		std::stack<float>  _stack;

};

#endif
