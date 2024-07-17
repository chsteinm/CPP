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
	int	lvl = -1;
	while (++lvl < 4)
		if (complain == this->_lvl[lvl])
			break ;
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