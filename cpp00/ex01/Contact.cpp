#include <iostream>
#include <string>
#include <cctype>
#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Contact constructor called" << std::endl;
	this->is_set = false;
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

void	Contact::displayContactColumns(int x) const{
	if (this->is_set == false)
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

void	Contact::displayContactInfos() const {
	std::cout << "First name : " << this->_first_name << std::endl;
	std::cout << "Last name : " << this->_last_name << std::endl;
	std::cout << "Nickname : " << this->_nickname << std::endl;
	std::cout << "Phone number : " << this->_phone_number << std::endl;
	std::cout << "Darkest secret : " << this->_darkest_secret << std::endl;
}

void	Contact::setContact() {
	this->_first_name = "";
	while (this->_first_name.size() == 0) {
		std::cout << "Tape first name :" << std::endl << "> ";
		std::getline(std::cin, this->_first_name);
		if (std::cin.eof())
			return ;
		while (this->_first_name.size() && isspace(this->_first_name[0]))
			this->_first_name.erase(this->_first_name.begin());
	}
	this->_last_name = "";
	while (this->_last_name.size() == 0) {
		std::cout << "Tape last name :" << std::endl << "> ";
		std::getline(std::cin, this->_last_name);
		if (std::cin.eof())
			return ;
		while (this->_last_name.size() && isspace(this->_last_name[0]))
			this->_last_name.erase(this->_last_name.begin());
	}
	this->_nickname = "";
	while (this->_nickname.size() == 0) {
		std::cout << "Tape nickname :" << std::endl << "> ";
		std::getline(std::cin, this->_nickname);
		if (std::cin.eof())
			return ;
		while (this->_nickname.size() && isspace(this->_nickname[0]))
			this->_nickname.erase(this->_nickname.begin());
	}
	this->_phone_number = "";
	while (this->_phone_number.size() == 0) {
		std::cout << "Tape phone number :" << std::endl << "> ";
		std::getline(std::cin, this->_phone_number);
		if (std::cin.eof())
			return ;
		while (this->_phone_number.size() && isspace(this->_phone_number[0]))
			this->_phone_number.erase(this->_phone_number.begin());
	}
	this->_darkest_secret = "";
	while (this->_darkest_secret.size() == 0) {
		std::cout << "Tape darkest secret :" << std::endl << "> ";
		std::getline(std::cin, this->_darkest_secret);
		if (std::cin.eof())
			return ;
		while (this->_darkest_secret.size() && isspace(this->_darkest_secret[0]))
			this->_darkest_secret.erase(this->_darkest_secret.begin());
	}
	std::cout << std::endl;
	this->is_set = true;
}