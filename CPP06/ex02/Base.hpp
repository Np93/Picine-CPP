#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base
{
	public:
		Base();
		virtual ~Base();
		Base(Base const &src);
		Base &operator=(Base const &rhs);

};

#endif
