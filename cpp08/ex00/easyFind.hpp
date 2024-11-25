# ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <limits>

template<typename T>
typename T::iterator	easyFind(T& a, int n) {
	return std::find(a.begin(), a.end(), n);
}

#endif