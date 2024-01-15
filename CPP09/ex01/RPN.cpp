#include "RPN.hpp"

RPN::RPN()
{
	return ;
}

RPN::~RPN()
{
	return;
}

RPN::RPN(RPN const &src)
{
	*this = src;
	return ;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	this->_stack = rhs._stack;
	return (*this);
}

bool	BadImput(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || (48 <= c && c <= 57))
		return (false);
	return (true);
}

void	RPN::Math(char *av)
{
	int i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		if (BadImput(av[i]))
		{
			std::cout << "Error\n";
			return;
		}
		if (isdigit(av[i]))
		{
			_stack.push((av[i] - 48));
			i++;
		}
		else
		{
			if (_stack.empty())
				std::cout << "Error\n";
		
			float tmp = _stack.top();
			float result;

			_stack.pop();
			if (_stack.empty())
				std::cout << "Error\n";
			switch(av[i])
			{
				case '*':
					result = _stack.top() * tmp;
					break;
				case '+':
					result = _stack.top() + tmp;
					break;
				case '-':
					result = _stack.top() - tmp;
					break;
				case '/':
					if (tmp == 0)
					{
						std::cout << "cannot divise whit 0:\n";
						return;
					}
					result = _stack.top() / tmp;
					break;;
			}
			_stack.pop();
			_stack.push(result);
			i++;
		}
	}
	std::cout << _stack.top() << std::endl;
	_stack.pop();
}
