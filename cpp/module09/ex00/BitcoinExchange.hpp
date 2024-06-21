#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <iterator>

typedef struct s_date {
	int	year;
	int	month;
	int	day;
}	t_date;

class BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

		//line checking
		static bool	split_line(std::string, std::string, std::string&, std::string&);
		
		//date checking
		static bool	in_date_format(std::string);
		static bool	in_history_range(std::string, t_date&);
		static bool	date_is_valid(std::string, t_date&);

		//value checking
		static double	value_is_valid(std::string);
		
		//perform calculations
		static void	performCalculations(std::string, double, std::map<std::string, double>);

		//get data from database
		static std::map<std::string, double>	getData(const std::string);
	public:
		static void	startProcessing(std::ifstream&);
};

#endif