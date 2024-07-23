#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Default Dog constuctor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& src) {
	std::cout << "Copy Dog constuctor called" << std::endl;
	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	if (this->_brain) {
		delete this->_brain;
	}
}

Dog&	Dog::operator=(const Dog& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = src._type;
	if (!this->_brain) {
		this->_brain = new Brain();
	}
	*this->_brain = *src._brain;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Whouf-whouf!" << std::endl;
}