# ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array {
private :
	T*				_array;
	unsigned int	_size;

public :
	Array();
	Array(unsigned int n);
	Array(const Array& src);
	~Array();
	Array&	operator=(const Array& src);

	T&	operator[](int n);

	unsigned int	size();
};

#endif