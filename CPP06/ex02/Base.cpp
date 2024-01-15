#include "Base.hpp"

Base::Base()
{
}

Base::~Base()
{
}

Base::Base(Base const &src)
{
	(void)src;
}

Base & Base::operator=(Base const &rhs)
{
	(void)rhs;
	return (*this);
}
