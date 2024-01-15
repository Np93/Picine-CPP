#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
//# include <string>
//# include <ctime>
# include <vector>
# include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe(int ac, char **av);
		void	result();
		std::vector<unsigned int>	sortVec(int ac, std::vector<unsigned int> vector);
		std::deque<unsigned int>	sortDeq(int ac, std::deque<unsigned int> deque);
//		double	getVectorDeltaTime(void) const;
		
		PmergeMe	&operator=(PmergeMe const &rhs);

	private:
//		int				_size;
		std::vector<unsigned int>	_vector;
		std::deque<unsigned int>	_deque;
		void				_printTime(double Time, std::string vectorDeque) const;
};

#endif
