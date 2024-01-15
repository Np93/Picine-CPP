#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_fpv;
	const static int	_bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &src);
	Fixed(int const n);
	Fixed(float const f);

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	int	toInt(void) const;
	float	toFloat(void) const;
	Fixed	&operator=(Fixed const &rhs);
};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);

#endif
