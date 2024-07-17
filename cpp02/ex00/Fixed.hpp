# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <map>

class Fixed {

private :
	int					_fixe;
	static const int	_bits = 8;

public :
	Fixed();
	Fixed(const Fixed& src);
	~Fixed();
	
	Fixed& operator=(const Fixed& src);

	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif