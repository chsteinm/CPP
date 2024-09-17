#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default ScalarConverter constuctor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	std::cout << "Copy ScalarConverter constuctor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {
	std::cout << "Copy assignment ScalarConverter operator called" << std::endl;
	(void)src;
	return *this;
}

bool	isInf(std::string& literal) {
	return literal == "-inf" || literal == "+inf" || literal == "-inff" || literal == "+inff";
}

void	convertInf(char sign) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << sign << "inff" << std::endl;
	std::cout << "double: " << sign << "inf" << std::endl;
}

bool	isChar(std::string& literal) {
	return literal.length() == 1 && !std::isdigit(literal[0]); 
}

void	convertChar(char c) {
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

bool	isInteger(std::string& literal, long int& value) {
	std::istringstream	iss(literal);
	iss >> value;
	return !iss.fail() && iss.eof();
}

void	convertInt(long int& value) {
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
		std::cout << "int: overflow" << std::endl;
		return ;
	}
	int	intValue = static_cast<int>(value);
	if (intValue < 127 && intValue > 31)
		std::cout << "char: " << static_cast<char>(intValue) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(intValue) << std::endl;
	std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
}

bool	isFloat(std::string& literal, float& value) {
	if (literal[literal.size() - 1] != 'f')
		return false;
	literal.erase(literal.size() - 1);
	std::istringstream	iss(literal);
	iss >> value;
	if (value == std::numeric_limits<float>::infinity() || value == -std::numeric_limits<float>::infinity())
		std::cout << value << "hoooo" << std::endl;
	return !iss.fail() && iss.eof();
}

void	convertFloat(float& value) {
	if (value < 127 && value > 31)
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	bool	hasDecimalPart = std::fmod(value, 1.0f) != 0.0f;
	if (hasDecimalPart == true) {
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
	else {
		std::cout << "float: " << value << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	}
}

void	ScalarConverter::convert(std::string literal) {
	long int	intValue;
	float		floatValue;
	if (isInf(literal))
		return convertInf(literal[0]);
	if (isChar(literal))
		return convertChar(literal[0]);
	if (isInteger(literal, intValue))
		return convertInt(intValue);
	if (isFloat(literal, floatValue))
		return convertFloat(floatValue);
}