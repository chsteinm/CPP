#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Constuctor called" << std::endl;
	this->levelMap["DEBUG"] = 0;
    this->levelMap["INFO"] = 1;
    this->levelMap["WARNING"] = 2;
    this->levelMap["ERROR"] = 3;
	this->f[0] = &Harl::debug;
	this->f[1] = &Harl::info;
	this->f[2] = &Harl::warning;
	this->f[3] = &Harl::error;
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
	(this->*f[this->levelMap[complain]])();
}