# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class Fixed {

private :
	static const int	_bits = 8;
	int					_fixe;

public :
	Fixed();
	Fixed(const Fixed& src);
	Fixed(const float n);
	Fixed(const int n);
	~Fixed();
	
	Fixed&	operator=(const Fixed& src);
	Fixed	operator+(const Fixed& src) const;
	Fixed	operator-(const Fixed& src) const;
	Fixed	operator*(const Fixed& src) const;
	Fixed	operator/(const Fixed& src) const;
	bool	operator>(const Fixed& src) const;
	bool	operator>=(const Fixed& src) const;
	bool	operator<(const Fixed& src) const;
	bool	operator<=(const Fixed& src) const;
	bool	operator==(const Fixed& src) const;
	bool	operator!=(const Fixed& src) const;
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed	min(Fixed& f1, Fixed& f2);
	static Fixed	min(const Fixed& f1, const Fixed& f2);
	static Fixed	max(Fixed& f1, Fixed& f2);
	static Fixed	max(const Fixed& f1, const Fixed& f2);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& src);

#endif