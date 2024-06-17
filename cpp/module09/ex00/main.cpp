#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::string inputFilename = argv[1];
	std::map<std::string, double> database = parseInputFile(inputFilename);

	std::string line;
	while (std::getline(std::cin, line)) {
		double exchangeRate = calculateExchangeRate(database, line);
		std::cout << exchangeRate << std::endl;
	}

	return 0;
}