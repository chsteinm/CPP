# ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>

class RPN {
private :
	std::stack<int> _stack;

public :
	RPN();
	RPN(const RPN& src);
	~RPN();
	RPN&	operator=(const RPN& src);

	int	calculator(char *args);
};

#endif