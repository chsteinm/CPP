#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Constuctor called" << std::endl;
	this->_levelMap["DEBUG"] = 0;
    this->_levelMap["INFO"] = 1;
    this->_levelMap["WARNING"] = 2;
    this->_levelMap["ERROR"] = 3;
	this->_f[0] = &Harl::debug;
	this->_f[1] = &Harl::info;
	this->_f[2] = &Harl::warning;
	this->_f[3] = &Harl::error;
}

Harl::~Harl() {
	std::cout << "Destructor called" << std::endl << std::endl;
}

void	Harl::debug() {
	std::cout << "FUUUUUUUUUU" << std::endl << std::endl;
}

void	Harl::info() {
	std::cout << "I'M FUUUUUUUUUUU" << std::endl << std::endl;
}

void	Harl::warning() {
	std::cout << "WARNING, I'M FUUUUUUUUUUU" << std::endl << std::endl;
}

void	Harl::error() {
	std::cout << "FUUUuuu...404" << std::endl;
}

void	Harl::complain(std::string complain) {
	int	lvl = this->_levelMap[complain];
	if (lvl == 0 && complain != "DEBUG")
		lvl = -1;
	switch (lvl) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*_f[0])();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*_f[1])();
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*_f[2])();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*_f[3])();
			break ;
		default :
			std::cout << "[ BIIIIP ]" << std::endl;
	}
}