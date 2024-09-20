#include "Array.hpp"

Array::Array() {
	std::cout << "Default Array constuctor called" << std::endl;
	this->_type = "defaultType";
}

Array::Array(const Array& src) {
	std::cout << "Copy Array constuctor called" << std::endl;
	*this = src;
}

Array::Array(std::string type) : _type(type) {
	std::cout << "Parametric Array constuctor called" << std::endl;
}

Array::~Array() {
	std::cout << "Array destructor called" << std::endl;
}

Array&	Array::operator=(const Array& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

void	Array::makeSound() const {
	std::cout << "Prout" << std::endl;
}

std::string	Array::getType() const {
	return this->_type;
}
