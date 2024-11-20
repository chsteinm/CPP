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
	int n;
	char op;

	while (!iss.fail() && iss >> std::ws) {
		if (iss >> n) {
			this->_stack.push(n);
		}
		else if (iss >> op) {
			if (this->_stack.size() != 2)
				return error("Error: number(s)");
			int b = this->_stack.top();
			std::cout << b << ' ';
			this->_stack.pop();
			int a = this->_stack.top();
			std::cout << a << '\n';
			this->_stack.pop();
			
			switch (op) {
				case '+': this->_stack.push(a + b); break;
                case '-': this->_stack.push(a - b); break;
                case '*': this->_stack.push(a * b); break;
                case '/': this->_stack.push(a / b); break;
                default: return error("Error: op");
            }
		}
	}
	std::cout << this->_stack.top() << std::endl;
	return 0;
}