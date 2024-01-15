#include "Data.hpp"

Data::Data()
{
	this->_value = "Default";
	std::cout << "Construtor of Data is created by default\n";
}

Data::~Data()
{
	std::cout << "Data is destroy\n";	
}

Data::Data(std::string value) : _value(value)
{
	std::cout << "Construtor of Data is created\n";
}

Data::Data(Data const &src)
{
	_value = src.getValue();
	std::cout << "Copy of Data\n";
}

Data &Data::operator=(Data const &rhs)
{
	this->_value = rhs.getValue();
	return (*this);
}

std::string Data::getValue(void) const
{
	return (this->_value);
}
