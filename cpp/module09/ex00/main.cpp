#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2)
	{
		std::cout << "Error : could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::ifstream	_file(av[1]);
	try
	{
		BitcoinExchange::startProcessing(_file);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	return (0);
}