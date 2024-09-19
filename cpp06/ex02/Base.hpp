# ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base {
public :
	Base();
	Base(const Base& src);
	virtual ~Base();
	Base&	operator=(const Base& src);

	static Base*	generate();
	void	identify(Base* p);
	void	identify(Base& p);
};

#endif