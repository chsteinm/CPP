#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : _MutantStack(0) {
	std::cout << "Default MutantStack constuctor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src) {
	std::cout << "Copy MutantStack constuctor called" << std::endl;
	*this = src;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	while (empty())
		pop();
	this->_vec = src.getVector();
	for (std::vector<T>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
		push(*it);
	return *this;
}

template <typename T>
std::vector<T>	MutantStack<T>::getVector() const {
	return this->_vec;
}