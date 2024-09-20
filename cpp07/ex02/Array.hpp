# ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
private :

public :
	Array();
	Array(unsigned int n);
	Array(const Array& src);
	~Array();
	Array&	operator=(const Array& src);

	static void	convert(std::string literal);
};

#endif