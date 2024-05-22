#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> _wallet;
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

public:
	BitcoinExchange(std::map<std::string, double> wallet);
	~BitcoinExchange();
};

#endif