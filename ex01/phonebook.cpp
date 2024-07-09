#include <iostream>
#include <limits>
#include "Phonebook.hpp"

Phonebook::Phonebook() {
	std::cout << "Phonebook constructor called" << std::endl;
	this->index_of_last_contacts_set = -1;
}

Phonebook::~Phonebook() {
	std::cout << "Phonebook destructor called" << std::endl;
}

void	Phonebook::displayColumns() const{
	int i;
	
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
	std::cout << "Select index : " << std::endl << "> ";
	while (!(std::cin >> i)) {
		if (std::cin.eof())
			return ;
		std::cout << "Error, please tape only a number" << std::endl << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (i < 1 || i > 8 || this->contacts[i - 1].is_set == false)
		std::cout << "Please select an existant index" << std::endl;
	else
		this->contacts[i - 1].displayContactInfos();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	Phonebook::addContact() {
	this->index_of_last_contacts_set++;
	if (this->index_of_last_contacts_set > 7)
		this->index_of_last_contacts_set = 0;
	this->contacts[this->index_of_last_contacts_set].setContact();
}