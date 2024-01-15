#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm> 
# include <vector>
# include <iterator>
# include <cmath>

typedef std::vector<int>::iterator my_iter;

class Span
{
	private:
		unsigned int	_n_int;
		unsigned int	_n_cont;
		std::vector<int>	_vec;

	public:
		Span(unsigned int n_int);
		~Span();
		Span(Span const &src);
		Span const &operator=(Span const &rhs);

		Span(int first, int last, int jump);

		unsigned int	get_n_int(void) const;
		unsigned int	get_n_cont(void) const;
		std::vector<int> get_vec(void) const;

		void	addNumber(int n);
		int	longestSpan(void);
		int	shortestSpan(void);

		void	addNumber(my_iter start, my_iter end);
};

std::ostream & operator<<( std::ostream &out, Span const & rhs);

#endif
