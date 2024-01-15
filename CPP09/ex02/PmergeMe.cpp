#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return ;
}

PmergeMe::~PmergeMe()
{
	return ;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	this->_deque = rhs._deque;
	this->_vector = rhs._vector;

	return (*this);
}

PmergeMe::PmergeMe(int ac, char **av)
{
	int i = 0;
	while (av[++i] != NULL)
	{
		_vector.push_back( std::atoi(av[i]) );
		_deque.push_back( std::atoi(av[i]) );
	}
	std::cout << "Before: ";
	i = 1;
	while (av[i])
	{
		std::cout << std::atoi(av[i]) << " ";
		i++;
		if (i > 21)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
	
	clock_t start;
	clock_t end;
	double time;
		
	start = clock();
	_vector = sortVec(ac - 1, _vector);
	end = clock();
	time = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
	result();
	_printTime(time, "vector");

	start = clock();
	_deque = sortDeq(ac - 1, _deque);
	end = clock();
	time = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
	_printTime(time, "deque");
}

std::vector<unsigned int>	PmergeMe::sortVec(int ac, std::vector<unsigned int> vector)
{
	const int band = (ac / 2);
	const int size = vector.size();
	if (ac < 2 && vector[0] > vector[1])
		return (vector);
	if (size < band || ac <= 3)
	{
		for(std::vector<unsigned int>::iterator i = vector.begin(); i != vector.end(); i++)
		{
			std::vector<unsigned int>::iterator s = i;
			while (s != vector.begin() && *s < *(s - 1))
			{
				std::swap(*s, *(s - 1));
				--s;
			}
		}
		return (vector);
	}
	std::vector<unsigned int>::iterator mid = vector.begin() + size / 2;
	std::vector<unsigned int> Le(vector.begin(), mid);
	std::vector<unsigned int> Ri(mid, vector.end());
	Le = sortVec(ac, Le);
	Ri = sortVec(ac, Ri);
	std::vector<unsigned int>::iterator v = vector.begin();
	std::vector<unsigned int>::iterator l = Le.begin();
	std::vector<unsigned int>::iterator r = Ri.begin();
	while (r != Ri.end() && l != Le.end())
	{
		if (*l < *r)
		{
			*v = *l;
			++l;
		}
		else
		{
			*v = *r;
			++r;
		}
		++v;
	}
	while (l != Le.end())
	{
		*v = *l;
		++l;
		++v;
	}
	while (r != Ri.end())
	{
		*v = *r;
		++r;
		++v;
	}
	return (vector);
}

std::deque<unsigned int>	PmergeMe::sortDeq(int ac, std::deque<unsigned int> deque)
{
	const int band = (ac / 2);
	const int size = deque.size();
	if (ac < 2 && deque[0] > deque[1])
		return (deque);
	if (size < band || ac <= 3)
	{
		for(std::deque<unsigned int>::iterator i = deque.begin(); i != deque.end(); i++)
		{
			std::deque<unsigned int>::iterator s = i;
			while (s != deque.begin() && *s < *(s - 1))
			{
				std::swap(*s, *(s - 1));
				--s;
			}
		}
		return (deque);
	}
	std::deque<unsigned int>::iterator mid = deque.begin() + size / 2;
	std::deque<unsigned int> Le(deque.begin(), mid);
	std::deque<unsigned int> Ri(mid, deque.end());
	Le = sortDeq(ac, Le);
	Ri = sortDeq(ac, Ri);
	std::deque<unsigned int>::iterator v = deque.begin();
	std::deque<unsigned int>::iterator l = Le.begin();
	std::deque<unsigned int>::iterator r = Ri.begin();
	while (r != Ri.end() && l != Le.end())
	{
		if (*l < *r)
		{
			*v = *l;
			++l;
		}
		else
		{
			*v = *r;
			++r;
		}
		++v;
	}
	while (l != Le.end())
	{
		*v = *l;
		++l;
		++v;
	}
	while (r != Ri.end())
	{
		*v = *r;
		++r;
		++v;
	}
	return (deque);
}

void	PmergeMe::result()
{
	std::cout << "After: ";
	unsigned int last = 0;
	int i = 0;
	for (std::vector<unsigned int>::iterator it = _vector.begin();
			it != _vector.end(); ++it)
	{
		i++;
	    	std::cout << *it << " ";
		last = *it;
		if (i > 20)
		{
			std::cout << "[...]";
			break;
		}
	}
  	std::cout << '\n';
	return;
}

void	PmergeMe::_printTime(double Time, std::string vectorDeque) const
{
	std::cout 
		<< "Time to process a range of " << _vector.size() 
		<< " elements with std::" << vectorDeque << ": "
		<< std::fixed << Time * 1000 << " ms" << std::endl;
}
