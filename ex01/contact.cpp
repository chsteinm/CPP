#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact() {
	std::cout << "Contact destructor called" << std::endl;
}

std::string	resize_if(std::string str){
	unsigned sz = str.size();
	if (sz > 10) {
		str.resize(9);
		str = str + '.';
	}
	return (str);
}

void	Contact::displayContactColumns(int x) {
	if (this->_first_name.size() == 0)
		return ;
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << x + 1;
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << resize_if(this->_first_name);
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << resize_if(this->_last_name);
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << resize_if(this->_nickname);
	std::cout << "|" << std::endl;
}