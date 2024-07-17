#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Constuctor called" << std::endl;
	this->_f[0] = &Harl::debug;
	this->_f[1] = &Harl::info;
	this->_f[2] = &Harl::warning;
	this->_f[3] = &Harl::error;
	this->_lvl[0] = "DEBUG";
	this->_lvl[1] = "INFO";
	this->_lvl[2] = "WARNING";
	this->_lvl[3] = "ERROR";
}

Harl::~Harl() {
	std::cout << "Destructor called" << std::endl;
}

void	Harl::debug() {
	std::cout << "FUUUUUUUUUU" << std::endl;
}

void	Harl::info() {
	std::cout << "I'M FUUUUUUUUUUU" << std::endl;
}

void	Harl::warning() {
	std::cout << "WARNING, I'M FUUUUUUUUUUU" << std::endl;
}

void	Harl::error() {
	std::cout << "FUUUuuu...404" << std::endl;
}

void	Harl::complain(std::string complain) {
	for (int i = 0; i < 4; i++)
		if (complain == this->_lvl[i])
			(this->*_f[i])();
}