#include "Fixed.hpp"

Fixed::Fixed() : _fixe(0) {
	// std::cout << "Default constuctor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	// std::cout << "Copy constuctor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const float n) {
	this->_fixe = roundf((n * (1 << this->_bits)));
}

Fixed::Fixed(const int n) {
	this->_fixe = n << this->_bits;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& src) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixe = src.getRawBits();
	return *this;
}

bool	Fixed::operator>( const Fixed& src ) const {
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator>=( const Fixed& src ) const {
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator<( const Fixed& src ) const {
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator<=( const Fixed& src ) const {
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator==( const Fixed& src ) const {
	return (this->toFloat() == src.toFloat());
}

bool	Fixed::operator!=( const Fixed& src ) const {
	return (this->toFloat() != src.toFloat());
}

Fixed	Fixed::operator+(const Fixed& src) const {
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(const Fixed& src) const {
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(const Fixed& src) const {
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(const Fixed& src) const {
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed&	Fixed::operator++() {
	this->_fixe++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed&	Fixed::operator--() {
	this->_fixe--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	--*this;
	return temp;
}

int		Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixe;
}

float	Fixed::toFloat() const {
	return (float)this->_fixe / (1 << this->_bits);
}

int	Fixed::toInt() const {
	return this->_fixe >> this->_bits;
}

Fixed	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (Fixed(f2));
	return (Fixed(f1));
}

Fixed	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (Fixed(f2));
	return (Fixed(f1));
}

Fixed	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 >= f2)
		return (Fixed(f1));
	return (Fixed(f2));
}

Fixed	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 >= f2)
		return (Fixed(f1));
	return (Fixed(f2));
}

std::ostream& operator<<(std::ostream& o, const Fixed& src) {
	o << src.toFloat();
	return o;
}