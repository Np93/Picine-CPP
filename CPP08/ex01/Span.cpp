#include "Span.hpp"

Span::Span(unsigned int n_int) : _n_int(n_int)
{
	_vec.reserve(n_int);//donne une capaciter de stocage de taille n_int
	_n_cont = 0;
}

Span::~Span()
{

}

Span::Span(Span const &src) : _n_int(src._n_int), _vec(src._vec)
{
	_n_cont = src._vec.size();
}

Span  const &Span::operator=(Span const &rhs)
{
	this->_n_int = rhs._n_int;
	this->_vec = rhs._vec;
	this->_n_cont = rhs._vec.size();
	return (*this);
}

unsigned int	Span::get_n_int(void) const
{
	return (_n_int);
}

unsigned int	Span::get_n_cont(void) const
{
	return (_n_cont);
}

std::vector<int> Span::get_vec(void) const
{
	return (_vec);
}

Span::Span(int first, int last, int jump)
{
	int f, l;
	if (last > first)
	{
		f = first;
		l = last;
	}
	else
	{
		f = last;
		l = first;
	}
	if (jump > l)
		throw(std::out_of_range("the jump is bigger of the last number"));
	_n_int = std::abs((last - first) / jump);
	_vec.reserve(_n_int);
	_n_cont = _n_int;
	for (int i = f; i < l; i += jump)
		_vec.push_back(i);
}

void	Span::addNumber(int n)
{
	if (_vec.size() >= _n_int || _n_cont >= _n_int)
		throw(std::out_of_range("Cannot add any more elements"));
	_vec.push_back(n);//ajoute un nouvelle element et agrandi la liste si besoin
	_n_cont += 1;
}

void	Span::addNumber(my_iter start, my_iter end)
{
	if (start > end)
		return ;
	for (my_iter i = start; i <= end; i++)
		addNumber(*i);
}

int	Span::longestSpan(void)
{
	if (_n_cont <= 1)
		throw(std::out_of_range("Not enough elements for a span"));
	std::vector<int>::iterator min = std::min_element(_vec.begin(), _vec.end());//vas checker dans notre liste vec le plus petite eleemnt, parcour du debut a la fin.
	std::vector<int>::iterator max = std::max_element(_vec.begin(), _vec.end());
	int long_span = *max - *min;
	return (long_span);
}

int	Span::shortestSpan(void)
{
	if (_n_cont <= 1)
		throw(std::out_of_range("Not enough elements for a span"));
	std::vector<int>::iterator max = std::max_element(_vec.begin(), _vec.end());
	int short_span = *max;
	
	std::vector<int> c_v = _vec;//cree une copie de _vec
	std::sort(c_v.begin(), c_v.end());//trie la copie du plus petit au plsu grand du start au end
	for(unsigned int i = 0; i < c_v.size(); i++)
	{
		if (std::abs(c_v[i] - c_v[i + 1]) < short_span)
			short_span = std::abs(c_v[i] - c_v[i + 1]);//abs valeur absolue -1 = 1
	}
	return (short_span);
}

std::ostream & operator<<( std::ostream & out, Span const & rhs)
{
	std::cout << "Span contents: ";
	for (unsigned int i = 0; i < rhs.get_n_cont(); i++)
		std::cout << (rhs.get_vec())[i] << " ";
	std::cout << std::endl;
	return (out);
}
