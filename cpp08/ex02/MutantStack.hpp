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
};

#endif