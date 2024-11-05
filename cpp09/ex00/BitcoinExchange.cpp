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
	while (std::getline(data, line)) {
		std::istringstream ss(line);
		std::string date;
		double exchangeRate;

		std::getline(ss, date, ',');
		ss >> exchangeRate;
		this->_change[date] = exchangeRate;
	}
}

double	BitcoinExchange::getChange(std::string date) {
	double ret;
	
	return ret;
}