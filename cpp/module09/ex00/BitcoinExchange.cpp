#include "BitcoinExchange.hpp"

double	ft_strtod(std::string value)
{
	char	*endPtr;
	double	number = std::strtod(value.c_str(), &endPtr);
	return number;
}

void	BitcoinExchange::performCalculations(std::string date, double number, std::map<std::string, double> dataMap)
{
	std::map<std::string, double>::iterator it = dataMap.upper_bound(date);
	it--;
	std::cout << date << " => " << number << " = " << number * it->second << std::endl;
}

double	BitcoinExchange::value_is_valid(std::string value)
{
	double	number = ft_strtod(value);
	if (number >= static_cast<double>(0) && number <= static_cast<double>(1000))
		return number;
	return -1;
}

bool	BitcoinExchange::in_history_range(std::string date, t_date& s_date)
{
	// 날짜를 year, month, day로 나누어 저장
	s_date.year = atoi(date.substr(0, 4).c_str());
	s_date.month = atoi(date.substr(5, 7).c_str());
	s_date.day = atoi(date.substr(8, 10).c_str());
	if (s_date.year < 2009 || s_date.year > 2024 ||\
		s_date.month < 1 || s_date.month > 12 ||\
		s_date.day < 1 || s_date.day > 31)
			return false;
	// 2009년 1월 3일 이전의 날짜는 유효하지 않음
	if (s_date.year == 2009 && s_date.month == 1 && s_date.day < 3)
		return false;
	// 윤년 체크
	if ((s_date.year % 4 == 0 && s_date.year % 100 != 0) || s_date.year % 400 == 0)
	{
		if (s_date.month == 2 && s_date.day > 29)
			return false;
	}
	else
	{
		if (s_date.month == 2 && s_date.day > 28)
			return false;
	}
	return true;

}

bool	BitcoinExchange::in_date_format(std::string date)
{
	for (size_t i = 0; i < date.length(); i++)
	{
		// 4번째와 7번째 문자가 '-'인지 확인
		if ((i == 4 || i == 7) && date[i] != '-')
			return false;
		// 4번째와 7번째 문자를 제외한 나머지 문자가 숫자인지 확인
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return false;
	}
	return true;
}

bool	BitcoinExchange::date_is_valid(std::string date, t_date& s_date)
{
	// 날짜 형식이 맞는지 확인
	if (in_date_format(date) == false)
		return false;
	// 날짜가 유효한 범위에 있는지 확인
	if (in_history_range(date, s_date) == false)
		return false;
	return true;	
}


bool	BitcoinExchange::split_line(std::string line, std::string del, std::string& date, std::string& value)
{
	// 구분자가 line에 있는지 확인
	size_t	delPos = line.find(del);
	// delpos가 문자열의 끝이 아닌지 확인
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
		if (BitcoinExchange::split_line(line, ",", date, value) == false)
		{
			std::cout << "Error : line isn't complete." << std::endl;
			continue;
		}
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