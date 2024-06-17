#include "BitcoinExchange.hpp"

std::map<std::string, double> parseInputFile(const std::string &filename)
{
	std::map<std::string, double> data;
	std::ifstream inputFile(filename);
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			std::map<std::string, double> tokens = split(line, ' ');
			for (std::map<std::string, double>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
			{
				data[it->first] = it->second;
			}
		}
		inputFile.close();
	}
	else
	{
		std::cerr << "Error: Unable to open file" << std::endl;
	}
	return data;
}

double calculateExchangeRate(const std::map<std::string, double> &database, const std::string &date)
{
	std::map<std::string, double>::const_iterator it = database.lower_bound(date);
	if (it == database.end())
	{
		// 날짜를 찾을 수 없으면 가장 가까운 이전 날짜를 사용
		if (database.empty())
		{
			std::cerr << "Error: Database is empty" << std::endl;
			return 0.0;
		}
		it--;
	}
	return it->second;
}

std::map<std::string, double> split(const std::string &str, char delimiter)
{
	std::map<std::string, double> tokens;
	std::string token;
	std::istringstream tokenStream(str);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens[token] = 0.0;
	}
	return tokens;
}