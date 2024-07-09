#include <iostream>
#include "Phonebook.hpp"

Phonebook::Phonebook() {
	std::cout << "Phonebook constructor called" << std::endl;
}

Phonebook::~Phonebook() {
	std::cout << "Phonebook destructor called" << std::endl;
}

void	Phonebook::displayColumns() {
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << "index";
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << "first name";
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << "last name";
	std::cout << "|";
	std::cout.width(10); std::cout << std::right << "nick name";
	std::cout << "|" << std::endl;
	for (int x = 0; x < 8; x++) {
		this->contacts[x].displayContactColumns(x);
	}
}