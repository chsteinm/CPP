#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Default Dog constuctor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& src) {
	std::cout << "Copy Dog constuctor called" << std::endl;
	*this = src;
}

Dog::Dog(std::string type) {
	std::cout << "Parametric Dog constuctor called" << std::endl;
	this->_type = type;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Whouf-whouf!" << std::endl;
}