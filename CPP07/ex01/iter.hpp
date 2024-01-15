#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *table, int len, void f(T const &ref))
{
	for (int i = 0; i < len; i++)
		f(table[i]);
}

template<typename T>
void	random(T const &ref)
{
	std::cout << ref << " ";
}

#endif
