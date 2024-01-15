#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

class Converter
{
	private:
		std::string	_str;

	public:
		Converter();
		~Converter();
		Converter(std::string str);
		Converter(Converter const &src);
		Converter	&operator=(Converter const &src);
	
		std::string	getStr(void) const;
	
		operator	char();
		operator	int();
		operator	float();
		operator	double();	
};

#endif
