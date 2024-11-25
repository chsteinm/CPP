# ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T> {
public :
	MutantStack() : std::stack<T>() {
		std::cout << "Default MutantStack constuctor called" << std::endl;
	}
	MutantStack(const MutantStack& src) : std::stack<T>(src) {
		std::cout << "Copy MutantStack constuctor called" << std::endl;
	}
	~MutantStack() {
		std::cout << "MutantStack destructor called" << std::endl;
	}
	MutantStack&	operator=(const MutantStack& src) {
		std::cout << "Copy assignment operator called" << std::endl;
		if (this != &src)
			std::stack<T>::operator=(src);
		return *this;
	}

	typedef typename std::deque<T>::iterator iterator;
	iterator	begin() {
		return this->c.begin();
	}
	iterator	end() {
		return this->c.end();
	}

	typedef typename std::deque<T>::const_iterator const_iterator;
	const_iterator	cbegin() {
		return this->c.begin();
	}
	const_iterator	cend() {
		return this->c.end();
	}

	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator rend() {
		return this->c.rend();
	}

	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin() {
		return this->c.rbegin();
	}
	const_reverse_iterator crend() {
		return this->c.rend();
	}
};

#endif