#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	private:
		std::string _value;

	public:
		Data();
		~Data();
		Data(std::string value);
		Data(Data const &src);
		
		Data	&operator=(Data const &rhs);
		
		std::string	getValue(void) const; 
};

#endif
