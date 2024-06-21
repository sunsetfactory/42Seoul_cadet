#include "BitcoinExchange.hpp"

double	ft_strtod(std::string value)
{
	char	*endPtr;
	double	number = std::strtod(value.c_str(), &endPtr);
	return number;
}

bool	BitcoinExchange::split_line(std::string line, std::string del, std::string& date, std::string& value)
{
	// 구분자가 line에 있는지 확인
	size_t	delPos = line.find(del);
	// 구분자가 있으면 date와 value에 나누어 저장
	if (delPos != std::string::npos)
	{
		date = line.substr(0, delPos);
		value = line.substr(delPos + del.length());
		return (true);
	}
	return (false);
}

std::map<std::string, double>	BitcoinExchange::getData(const std::string dataPath)
{
	std::map<std::string, double>	dataMap;
	std::ifstream	_file(dataPath);
	
	if (!_file.is_open())
	{
		throw std::exception();
	}
	std::string	line;
	std::getline(_file, line);
	while (std::getline(_file, line))
	{
		std::string date;
		std::string value;
		BitcoinExchange::split_line(line, ",", date, value);
		dataMap[date] = ft_strtod(value);
	}
	_file.close();
	return dataMap;
}

void	BitcoinExchange::startProcessing(std::ifstream& _file)
{
	// 파일이 열렸는지 확인
	if (_file.is_open()) {
		std::map<std::string, double> dataMap;
		std::string	line;
		// 데이터베이스에서 데이터를 가져옴
		try 
		{
			dataMap = getData(std::string("./data.csv"));
		}
		catch (...)
		{
			throw std::runtime_error("Can't read data from database");
		}
		// 파일의 첫 줄이 "date | value"인지 확인
		std::getline(_file, line);
		if (line != std::string("date | value"))
			throw std::runtime_error("File format not valid");
		while (std::getline(_file, line))
		{
			std::string	date;
			std::string value;
			// line을 " | "로 나누어 date와 value에 저장
			if (!BitcoinExchange::split_line(line, " | ", date, value))
			{
				std::cout << "Error : line isn't complete." << std::endl;
				continue;
			}
			t_date	s_date;
			// date가 유효한지 확인
			if (BitcoinExchange::date_is_valid(date, s_date))
			{
				// value가 유효한지 확인
				double number = BitcoinExchange::value_is_valid(value);
				if (number == -1)
				{
					std::cout << "Error : value is not valid." << std::endl;
					continue;
				}
				// 계산 수행
				performCalculations(date, number, dataMap);
			}
			else
			{
				std::cout << "Error : date is not valid." << std::endl;
				continue;
			}
		}
		_file.close();
		return ;
	}
	throw std::runtime_error("Can't open file.");
}