# ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

template<typename T>
std::vector<int>::iterator	easyfind(T& a, int n) {
	return std::find(a.begin(), a.end(), n);
}

#endif