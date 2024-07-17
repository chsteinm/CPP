#include "Fixed.hpp"

Fixed::Fixed() : _fixe(0) {
	std::cout << "Default constuctor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constuctor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixe = src.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixe;
}