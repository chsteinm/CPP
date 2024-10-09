#include "Fixed.hpp"

int	main( void ) {

Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << std::endl << b << std::endl << std::endl;

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << --a << std::endl;
std::cout << a << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
Fixed aBig(a);
aBig++;
std::cout << Fixed::min( a, aBig ) << std::endl;
std::cout << Fixed::max( a, aBig ) << std::endl;
Fixed const bBig(5.06f);
std::cout << Fixed::min( b, bBig ) << std::endl;
std::cout << Fixed::max( b, bBig ) << std::endl << std::endl;

std::cout << "a > b is " << (a > b) << std::endl;
std::cout << "a < b is " << (a < b) << std::endl;
std::cout << "a <= b is " << (a <= b) << std::endl;
std::cout << "a >= b is " << (a >= b) << std::endl;
std::cout << "a == b is " << (a == b) << std::endl;
std::cout << "a != b is " << (a != b) << std::endl << std::endl;

std::cout << "a = " << a << std::endl;
std::cout << "b = " << b << std::endl;
a = b + b;
std::cout << "a = b + b = " << a << std::endl;
a = a * b;
std::cout << "a = a * b = " << a << std::endl;
a = a - b;
std::cout << "a = a - b = " << a << std::endl;
a = a / 2;
std::cout << "" << a << std::endl;
return 0;
}