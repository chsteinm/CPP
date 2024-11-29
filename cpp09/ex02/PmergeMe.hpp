# ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>

class PmergeMe {
private :
	std::stack<int> _stack;

public :
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	~PmergeMe();
	PmergeMe&	operator=(const PmergeMe& src);

	int	calculator(char *args);
};

#endif