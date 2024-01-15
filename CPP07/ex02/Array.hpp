#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int	_n;
		T		*_t;

	public:
		Array()
		{
			_n = 0;
			_t = new T[1];
			_t[0] = 0;
		}
		~Array()
		{
			delete [] this->_t;
		}
		Array(unsigned int n) : _n(n)
		{
			_t = new T[n];
		}
		Array(Array const &src) : _n(src.size())
		{
			T *src_t = src.getT();
			_t = new T[_n];
			for(unsigned int i = 0; i < _n; i++)
				_t[i] = src_t[i];
		}
		Array	&operator=(Array const &rhs)
		{
			T *rhs_t = rhs.getT();
			this->_n = rhs.size();
			delete [] this->_t;
			this->_t = new T[_n];
			for(unsigned int i = 0; i < _n; i++)
				_t[i] = rhs_t[i];
			return (*this); 
		}
		T	*getT(void) const {return (_t);}
		unsigned int	size(void) const {return (_n);}
		T	&operator[](int i)
		{
			if (i < 0 || i >= static_cast<int>(this->_n))
			{
				throw (std::exception());
			}
			else
				return (*(_t + i));
		}
};

template< typename T >
std::ostream & operator<<(std::ostream & o, Array< T > const & rhs)
{
	for (unsigned int i = 0; i < rhs.size(); i++)
		std::cout << "T[" << i << "] : " << (rhs.getT())[i] << std::endl;
	return (o);
}

#endif
