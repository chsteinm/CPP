#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Default WrongAnimal constuctor called" << std::endl;
	this->_type = "defaultType";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << "Copy WrongAnimal constuctor called" << std::endl;
	*this = src;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "Parametric WrongAnimal constuctor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Prout" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->_type;
}
