#include "Span.hpp"

Span::Span() : _max(10000) {
	std::cout << "Default Span constuctor called" << std::endl;
}

Span::Span(const Span& src) {
	std::cout << "Copy Span constuctor called" << std::endl;
	this->_max = src.getMax();
	this->_numbers = src.getVector();
}

Span::~Span() {
	std::cout << "Span Destructor called" << std::endl;
}

Span&	Span::operator=(const Span& src) {
	std::cout << "Copy assignment Span operator called" << std::endl;
	this->_max = src.getMax();
	this->_numbers = src.getVector();
	return *this;
}

int&	Span::operator[](int n) {
	return (this->_numbers[n]);
}

Span::Span(unsigned int n) : _max(n) {
	std::cout << "Parametric Span constuctor called" << std::endl;
}

unsigned int Span::getMax() const {
	return this->_max;
}

std::vector<int>	Span::getVector() const {
	return this->_numbers;
}

int	Span::getSize() const {
	return this->_numbers.size();
}

void	Span::addNumber(const int n) {
	if (this->_numbers.size() >= this->_max)
		throw Span::MaxNumbersReach();
	this->_numbers.push_back(n);
}

const char*	Span::MaxNumbersReach::what() const throw() {
	return "Max numbers reach";
}

const char*	Span::LessThanTwoNumbers::what() const throw() {
	return "Not enought numbers";
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

int	Span::shortestSpan() const {
	int	size = this->_numbers.size();
	if (size < 2)
		throw Span::LessThanTwoNumbers();
	int	min = std::numeric_limits<int>::max();
	std::vector<int> sortedNumbers(this->_numbers);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int	tmp;
	for (int i = 1; i < size; i++) {
		tmp = sortedNumbers[i] - sortedNumbers[i - 1];
		min = std::min(tmp, min);
	}
	return min;
}

int 	Span::longestSpan() const {
	if (this->_numbers.size() < 2)
		throw Span::LessThanTwoNumbers();
	std::vector<int>::const_iterator it_min = std::min_element(this->_numbers.begin(), this->_numbers.end());
	std::vector<int>::const_iterator it_max = std::max_element(this->_numbers.begin(), this->_numbers.end());
	return *it_max - *it_min;
}