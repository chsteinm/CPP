#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Default Cat constuctor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& src) {
	std::cout << "Copy Cat constuctor called" << std::endl;
	*this = src;
}

Cat::Cat(std::string type) {
	std::cout << "Parametric Cat constuctor called" << std::endl;
	this->_type = type;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Miaou :3" << std::endl;
}