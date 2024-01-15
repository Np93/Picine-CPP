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

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed	&operator=(Fixed const &rhs);
};

#endif
