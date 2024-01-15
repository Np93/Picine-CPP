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

	// > < >= <= == !=
	int operator>(Fixed const &rhs) const;
	int operator<(Fixed const &rhs) const;
	int operator>=(Fixed const &rhs) const;
	int operator<=(Fixed const &rhs) const;
	int operator==(Fixed const &rhs) const;
	int operator!=(Fixed const &rhs) const;
		
	// + - * /
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;

	// ++F F++ --F F--
	Fixed & operator++(void); // Prefix (++F)
	Fixed & operator--(void); // Prefix (--F)
	Fixed operator++(int); // Postfix (F++)
	Fixed operator--(int); // Postfix (F--)

	// min & max
	static Fixed & min(Fixed &a, Fixed &b);
	static Fixed & max(Fixed &a, Fixed &b);
	static const Fixed & min(const Fixed &a, const Fixed &b);
	static const Fixed & max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);

#endif
