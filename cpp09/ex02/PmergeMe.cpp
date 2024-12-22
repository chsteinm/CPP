#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "Default PmergeMe constuctor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& src) {
	// std::cout << "Copy PmergeMe constuctor called" << std::endl;
	*this = src;
}

PmergeMe::~PmergeMe() {
	// std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& src) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_vec = src._vec;
	return *this;
}

void	affVec(std::vector<int> &vec) {
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end())
		std::cout << *it++ << " ";
}

void	PmergeMe::parse(int ac, char **av) {
	if (ac < 3)
		throw std::runtime_error("Please enter at least 2 integers");
	int n;
	for (int i = 1; av[i]; i++) {
		std::istringstream ss(av[i]);
		ss >> n;
		if (ss.fail() || !ss.eof() || n < 0)
			throw std::runtime_error("Please enter only integers betwen 0 and MAX_INT");
		this->_vec.push_back(n);
		this->_deq.push_back(n);
	}
	std::cout << "Before: ";
	affVec(this->_vec);
	std::cout << std::endl;
}




void	PmergeMe::vecSort() {
	this->_start = clock();

	this->_end = clock();
	double cpu_time_used = ((double) (this->_end - this->_start)) / CLOCKS_PER_SEC;
	std::cout << "After: "; affVec(this->_vec); std::cout << std::endl;
}