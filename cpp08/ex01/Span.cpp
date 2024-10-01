#include "Span.hpp"

Span::Span() : _max(10000) {
	std::cout << "Default Span constuctor called" << std::endl;
}

Span::Span(const Span& src) {
	std::cout << "Copy Span constuctor called" << std::endl;
	this->_max = src.getMax();
}

Span::~Span() {
	std::cout << "Span Destructor called" << std::endl;
}

Span&	Span::operator=(const Span& src) {
	std::cout << "Copy assignment Span operator called" << std::endl;
	(void)src;
	return *this;
}

Span::Span(unsigned int n) : _max(n) {
	std::cout << "Parametric Span constuctor called" << std::endl;
}

unsigned int Span::getMax() const {
	return this->_max;
}

void	Span::addNumber(const int n) {
	if (this->_numbers.size() >= this->_max)
		throw (Span::MaxNumbersReach());
	this->_numbers.push_back(n);
}

const char*	Span::MaxNumbersReach::what() const throw() {
	return "Max numbers reach";
}

int	randomNumber() {
	return rand();
}

void	Span::addMaxNumbers() {
	srand(time(NULL));
	std::vector<int>randomNumbers(this->_max - this->_numbers.size());
	std::generate(randomNumbers.begin(), randomNumbers.end(), randomNumber);
	this->_numbers.insert(this->_numbers.end(), randomNumbers.begin(), randomNumbers.end());
}