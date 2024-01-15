#include <iostream>
#include <string>

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "pas assez d'argument\n";
		return (1);
	}
	int i = 0;
	while (av[++i] != '\0')
	{
		if (av[i][0] == '\0')
		{
			std::cout << "bad argument\n";
			return (1);
		}
		for (int c = 0; av[i][c] != '\0'; c++)
		{
			if (av[i][c] < 48 || 57 < av[i][c])
			{
				std::cout << "bad argument\n";
				return (1);
			}
		}
		int j = std::atoi(av[i]);
		if (i != (ac - 1))
		{
			for (int c = (i + 1); av[c] != '\0'; c++)
			{
				if (j == std::atoi(av[c]))
				{
					std::cout << "double argument\n";
					return (1);
				}
			}
		}
		if (2147483647 > j && j < 0)
		{
			std::cout << "bad imput\n";
			return (1);
		}
	}
	PmergeMe start(ac, av);
	return (0);
}
