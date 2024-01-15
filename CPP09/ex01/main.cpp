#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "bug dans ce que tu me donne frerot\n";
		return (1);
	}
	RPN rpn;
	rpn.Math(av[1]);
	return (0);
}
