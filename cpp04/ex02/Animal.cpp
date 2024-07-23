#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default Animal constuctor called" << std::endl;
	this->_type = "defaultType";
}

Animal::Animal(const Animal& src) {
	std::cout << "Copy Animal constuctor called" << std::endl;
	*this = src;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Parametric Animal constuctor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "Prout" << std::endl;
}

std::string	Animal::getType() const {
	return this->_type;
}
