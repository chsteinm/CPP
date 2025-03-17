#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

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

void	PmergeMe::parse(int ac, char **av) {
	(void)ac;
	int n;
	for (int i = 1; av[i]; i++) {
		std::istringstream ss(av[i]);
		ss >> n;
		if (ss.fail() || !ss.eof() || n < 0)
			throw std::runtime_error("Please enter only integers betwen 0 and MAX_INT");
		if (std::find(_vec.begin(), _vec.end(), n) != _vec.end())
			throw std::runtime_error("Please enter only differents integers");
		this->_vec.push_back(n);
		this->_deq.push_back(n);
	}
	std::cout << "Before: ";
	affContainer(this->_vec);
}

void	PmergeMe::vecSort() {
	this->_cmp = 0;
	this->_start = clock();
	mergeInsertionSort(this->_vec);
	this->_end = clock();
	double cpu_time_used = (1000.0 * (this->_end - this->_start)) / CLOCKS_PER_SEC;
	std::cout << "After: "; affContainer(this->_vec);
	std::cout << "Time to process a range of 3000 elements with std::vector : " << cpu_time_used << " ms" << std::endl;
}

void	PmergeMe::dequeSort() {
	this->_cmp = 0;
	this->_start = clock();
	mergeInsertionSort(this->_deq);
	this->_end = clock();
	double cpu_time_used = (1000.0 * (this->_end - this->_start)) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of 3000 elements with std::deque : " << cpu_time_used << " ms" << std::endl;
	std::cout << "Number of comparisons: " << this->_cmp << std::endl;
	printSortedOrNot(this->_deq);
}