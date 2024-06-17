#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

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

std::map<std::string, double> split(const std::string &str, char delimiter);
std::map<std::string, double> parseInputFile(const std::string &filename);
double calculateExchangeRate(const std::map<std::string, double> &database, const std::string &date);

#endif
