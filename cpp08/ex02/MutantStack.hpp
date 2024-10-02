# ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>

template<typename T>
class MutantStack : public std::stack<T> {
private :
	std::vector<T>	_vec;

public :
	MutantStack();
	MutantStack(const MutantStack& src);
	~MutantStack();
	MutantStack&	operator=(const MutantStack& src);

	std::vector<T>	getVector() const;

	std::vector<T>::iterator	begin();
	std::vector<T>::iterator	end();
	
};

#endif