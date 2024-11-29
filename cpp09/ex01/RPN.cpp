#include "RPN.hpp"

RPN::RPN() {
	// std::cout << "Default RPN constuctor called" << std::endl;
}

RPN::RPN(const RPN& src) {
	// std::cout << "Copy RPN constuctor called" << std::endl;
	*this = src;
}

RPN::~RPN() {
	// std::cout << "RPN destructor called" << std::endl;
}

RPN&	RPN::operator=(const RPN& src) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_stack = src._stack;
	return *this;
}

int error(std::string err) {
    std::cerr << err << std::endl;
    return 1;
}

int	RPN::calculator(char *args) {
	
	std::istringstream iss(args);
	char c;

	while (iss >> std::skipws >> c) {
		if (c >= '0' && c <= '9') {
			this->_stack.push(c - 48);
		}
		else {
			if (this->_stack.size() != 2)
				return error("Error: n");
			int b = this->_stack.top();
			this->_stack.pop();
			int a = this->_stack.top();
			this->_stack.pop();
			
			switch (c) {
				case '+': this->_stack.push(a + b); break;
                case '-': this->_stack.push(a - b); break;
                case '*': this->_stack.push(a * b); break;
                case '/': if (!b)
							return error("Error: division by zero impossible");
						  this->_stack.push(a / b); break;
                default: return error("Error: op");
            }
		}
	}
	
	if (this->_stack.size() == 1)
		std::cout << this->_stack.top() << std::endl;
	else
		return error("Error");
	return 0;
}