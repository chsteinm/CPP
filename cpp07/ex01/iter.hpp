# ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename E>
E&	f(E& e) {
	return e += 1;
}

template<typename A, typename F>
void	iter(A* array, size_t lenght, F f) {
	for (size_t i = 0; i < lenght; i++) {
		f(array[i]);
	}
}

#endif