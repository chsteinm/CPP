# ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange {
private :
	std::map<std::string, double> _change;

public :
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange();
	BitcoinExchange&	operator=(const BitcoinExchange& src);

	void	parseData(std::ifstream& data);
	void	getChange(std::ifstream& input);
};

#endif