#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <iterator>
# include <vector>
# include <array>

template<typename T>
int easyfind(T const &t, int n)
{
	typename T::const_iterator end = t.end();
	typename T::const_iterator it = std::find(t.begin(), end, n);

	return (it == end ? throw(std::out_of_range("Element not found in given range")) : *it);
}

#endif
