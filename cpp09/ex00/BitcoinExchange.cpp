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

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isValidDate(const std::string& date) {
    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false; // Format incorrect
    }

    if (month < 1 || month > 12) {
        return false; // Mois invalide
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        daysInMonth[1] = isLeapYear(year) ? 29 : 28;
    }

    return day >= 1 && day <= daysInMonth[month - 1];
}

void	BitcoinExchange::parseData(std::ifstream& data) {
	std::string	line;
	std::getline(data, line);
	while (std::getline(data, line)) {
		std::istringstream ss(line);
		std::string date;
		double exchangeRate;

		std::getline(ss, date, ',');
		if (isValidDate(date)) {
			ss >> exchangeRate;
			if (!ss.fail())
				this->_change[date] = exchangeRate;
			else
				std::cout << "error in exchange_rate on the line : " << line << std::endl;
		}
		else
			std::cout << "error in date on the line : " << line << std::endl;

	}
}

double	BitcoinExchange::getChange(std::string date) {
	double ret;
	ret = this->_change[date];
	return ret;
}