#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "Default WrongCat constuctor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) {
	std::cout << "Copy WrongCat constuctor called" << std::endl;
	*this = src;
}

WrongCat::WrongCat(std::string type) {
	std::cout << "Parametric WrongCat constuctor called" << std::endl;
	this->_type = type;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "Miaou :3" << std::endl;
}