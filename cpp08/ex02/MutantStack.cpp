#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
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
	if (this != &src) {
		while (this->empty())
			this->pop();
		this->_vec = src.getVector();
		for (iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
			this->push(*it);
	}
	return *this;
}

template <typename T>
std::vector<T>	MutantStack<T>::getVector() const {
	return this->_vec;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->_vec.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->_vec.end();
}

template <typename T>
void	MutantStack<T>::push(const T& value) {
	std::stack<T>::push(value);
	this->_vec.push_back(value);
}

template <typename T>
void	MutantStack<T>::pop() {
	std::stack<T>::pop();
	this->_vec.pop_back();
}