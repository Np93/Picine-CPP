#include "Converter.hpp"
#include <limits.h>

Converter::Converter() : _str("Default")
{
	std::cout << "A Converter has been constructed by default\n";
}

Converter::Converter(std::string str) : _str(str)
{
	std::cout << "A Converter has been constructed\n";
}

Converter::~Converter()
{
	std::cout << "A Converter has been destroyed\n";
}

Converter::Converter(Converter const &src)
{
	_str = src.getStr();
}

Converter &Converter::operator=(Converter const & src)
{
	_str = src.getStr();
	return (*this);
}

std::string Converter::getStr(void) const
{
	return (this->_str);
}

int	is_pritable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return(0);
}

Converter::operator char()
{
	char c = 0;
	if (_str.length() == 1)
	{
		int i = 0;
		try
		{
			i = stoi(_str);
			c = static_cast<char>(i);
		}
		catch(const std::invalid_argument& ia)
		{
			c = _str[0];
		}
		if (is_pritable(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable\n";
		return (c);
	}
	else
	{
		int i = 0;
		try
		{
			i = stoi(_str);
		}
		catch(const std::invalid_argument &ia)
		{
			std::cout << "char: Impossible argument\n";
			return (0);
		}
		catch(const std::out_of_range &oor)
		{
			std::cout << "char: Impossible out of range\n";
			return (0);
		}
		if (i < CHAR_MIN || i > CHAR_MAX)
		{
			std::cout << "char: Impossible out of range\n";
			return (0);
		}
		c = static_cast<char>(i);
		if (is_pritable(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable\n";
		return (c);
	}
}

Converter::operator int()
{
	int	i = 0;
	try
	{
		i = stoi(_str);
	}
	catch(const std::invalid_argument &ia)
	{
		std::cout << "int: Impossible: invalid argument\n";
		return (0);
	}
	catch(const std::out_of_range &oor)
	{
		std::cout << "int: Impossible out of int range\n";
		return (0);
	}
	std::cout << "int: " << i << std::endl;
	return (i);
}

Converter::operator float()
{
	float	f = 0;
	try
	{
		f = stof(_str);
	}
	catch(const std::invalid_argument &ia)
	{
		std::cout << "float: Impossible invalid argument\n";
		return (0);
	}
	catch(const std::out_of_range &oor)
	{
		std::cout << "float: Impossible out of int range\n";
		return (0);
	}
	std::cout << "flaot: " << f << "f" << std::endl;
	return (f);
}

Converter::operator double()
{
	double	d = 0;
	try
	{
		d = stod(_str);
	}
	catch(const std::invalid_argument &ia)
	{
		std::cout << "double: Impossible invalid argument\n";
		return (0);
	}
	catch(const std::out_of_range& oor)
	{
		std::cout << "double: Impossible: out of int range\n";
		return (0);
	}
	std::cout << "double: " << d << std::endl;
	return (d);
}
