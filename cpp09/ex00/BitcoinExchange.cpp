#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "Default BitcoinExchange constuctor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	std::cout << "Copy BitcoinExchange constuctor called" << std::endl;
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_change = src._change;
	return *this;
}

void	BitcoinExchange::parseData(std::ifstream& data) {
	std::string	line;
	
}

double	BitcoinExchange::getChange(std::string date) {
	//
	double ret = this->_change[date];
	return ret;
}