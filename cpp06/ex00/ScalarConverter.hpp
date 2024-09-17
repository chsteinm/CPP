# ifndef SCALAIRCONVERTER_HPP
#define SCALAIRCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>

class ScalarConverter {
private :
	ScalarConverter();

public :
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter();
	ScalarConverter&	operator=(const ScalarConverter& src);

	static void	convert(std::string literal);
};

#endif