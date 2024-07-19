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

std::cout << "a > b is " << (a > b) << std::endl;
std::cout << "a < b is " << (a < b) << std::endl;
std::cout << "a <= b is " << (a <= b) << std::endl;
std::cout << "a >= b is " << (a >= b) << std::endl;
std::cout << "a == b is " << (a == b) << std::endl;
std::cout << "a != b is " << (a != b) << std::endl << std::endl;

a = b + b;
std::cout << a << std::endl;
a = a * b;
std::cout << a << std::endl;
a = a - b;
std::cout << a << std::endl;
a = a / 2;
std::cout << a << std::endl;
return 0;
}