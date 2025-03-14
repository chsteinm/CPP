# ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>

#ifndef DEBUG
#define DEBUG 0
#endif

class PmergeMe {
	private :
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		clock_t			_start;
		clock_t			_end;

		template <typename Container>
		void	mergeInsertionSort(Container& numbers);

	public :
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& src);

		void	parse(int ac, char **av);
		void	vecSort();
};

#endif