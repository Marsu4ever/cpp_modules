#pragma once

#include <iostream>
#include <fstream>		//std::ifstream, getline
#include <filesystem>	//fs::is_directory
#include <regex>
#include <string>		//substr
#include <map>			//std::map
#include <algorithm>	//std::max

struct data
{
	std::string		date;
	std::string		value_string;
	float			value;
	float			exchangeRate;
	float			total_value;
};

class BitcoinExchange
{
	private:
		std::map<std::string, float> btcExchangeHistory;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange&	operator=(const BitcoinExchange &other);

		// Get Bitcoin Exchange history
		int		InitDataCSV();
		void	getDateAndExchangeRate(std::string &line);		
		int		checkExchangeRate(std::string &exchange_rate_string);
		float	convertAndGetExchangeRate(std::string &exchange_rate_string, std::string &line);	

		// Main loop
		int		run(std::string bitcoin_file);
		int		IO_Checks(std::string &bitcoin_file, std::ifstream &in);
		void	readAndPrint(std::string &line);

		// Main Program
		void	initDefaultValues(data &obj);
		int		getDateAndValue(data &obj, std::string &line);
		int		checkValue(data &obj);
		int		convertValueToFloat(data &obj);
		void	calculateTotalValue(data &obj);
		void	print(data &obj);

		// checkDate
		int		checkDate(data &obj);
		int		furtherDateChecks(data &obj);
		bool	leapYearCheck(int year);

		// getExchangeRate
		int		getExchangeRate(data &obj);
		int		getNearestPreviousExchangeRate(data &obj);
		int		dateOutsideOfScope(data &obj);

};
