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
	this->_stack = src._stack;
	return *this;
}

int error(std::string err) {
    std::cerr << err << std::endl;
    return 1;
}

