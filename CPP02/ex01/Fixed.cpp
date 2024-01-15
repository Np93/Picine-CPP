#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->_fpv = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

int	Fixed::getRawBits(void)const
{
	return (this->_fpv);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpv = raw;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignation operator called" << std::endl;
	this->_fpv = rhs.getRawBits();
	return (*this);
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(n << this->_bits);
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)round(f * (1 << this->_bits)));
}

float Fixed::toFloat(void) const
{
	float	flo;

	flo = (float)this->getRawBits() / (1 << this->_bits);
	return (flo);
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_bits);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.toFloat();
	return (out);
}
