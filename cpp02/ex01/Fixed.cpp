#include "Fixed.hpp"

Fixed::Fixed() : _fixe(0) {
	std::cout << "Default constuctor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constuctor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const float n) {
	this->_fixe = roundf((n * (1 << this->_bits)));
}

Fixed::Fixed(const int n) {
	this->_fixe = n << this->_bits;
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

float	Fixed::toFloat() const {
	return (float)this->_fixe / (1 << this->_bits);
}

int	Fixed::toInt() const {
	return this->_fixe >> this->_bits;
}

std::ostream& operator<<(std::ostream& o, const Fixed& src) {
	o << src.toFloat();
	return o;
}