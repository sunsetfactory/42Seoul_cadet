#include "BitcoinExchange.hpp"

void	BitcoinExchange::startProcessing(std::ifstream& _file) {
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
		while (std::getline(_file, line)) {
			std::string	date;
			std::string value;
			if (!BitcoinExchange::split_line(line, " | ", date, value)) {
				std::cout << "Error : line isn't complete." << std::endl;
				continue;
			}
			t_date	s_date;
			if (BitcoinExchange::date_is_valid(date, s_date)) {
				double number = BitcoinExchange::value_is_valid(value);
				if (number == -1) {
					std::cout << "Error : value is not valid." << std::endl;
					continue;
				}
				performCalculations(date, number, dataMap);
			} else {
				std::cout << "Error : date is not valid." << std::endl;
				continue;
			}
		}
		_file.close();
		return ;
	}
	throw std::runtime_error("Can't open file.");
}