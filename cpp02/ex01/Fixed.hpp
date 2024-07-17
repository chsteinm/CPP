# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
	
	Fixed& operator=(const Fixed& src);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& src);

#endif