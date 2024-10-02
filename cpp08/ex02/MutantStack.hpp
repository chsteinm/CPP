# ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <list>

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

	typedef typename std::vector<T>::iterator iterator;
	iterator	begin();
	iterator	end();

	void	push(const T& value);
	void	pop();
};

#endif