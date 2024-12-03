# ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <sstream>
#include <ctime>

class PmergeMe {
private :
	std::vector<int> _vec;
	std::deque<int> _deq;
	time_t	_start;

public :
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	~PmergeMe();
	PmergeMe&	operator=(const PmergeMe& src);

	void	parse(int ac, char **av);
};

#endif