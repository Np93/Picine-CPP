#include <iostream>
#include <iomanip>
#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong number of argument\n";
		return (0);
	}
	std::cout << std::fixed << std::setprecision(1);
	std::string	argument = argv[1];
	
	Converter	converter(argument);

	char	c;
	int	i;
	float	f;
	double	d;

	c = static_cast<char>(converter);
	i = static_cast<int>(converter);
	f = static_cast<float>(converter);
	d = static_cast<double>(converter);

	return (0);
}
