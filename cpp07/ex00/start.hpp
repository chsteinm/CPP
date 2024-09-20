# ifndef START_HPP
#define START_HPP

#include <iostream>

template<typename T>
const T&	max(const T& a, const T& b) {
	return (a > b ? a : b);
}

template<typename T>
const T&	min(const T& a, const T& b) {
	return a < b ? a : b;
}

template<typename T>
void	swap( T& a, T& b) {
	T cpy = a;
	a = b;
	b = cpy;
}

#endif