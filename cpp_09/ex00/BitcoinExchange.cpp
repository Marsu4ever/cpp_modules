#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->btcExchangeHistory = other.btcExchangeHistory;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->btcExchangeHistory = other.btcExchangeHistory;
	}
	return (*this);
}

int		BitcoinExchange::checkExchangeRate(std::string &exchange_rate_string)
{
	std::regex	exchange_rate_pattern("[+]?[0-9]+[.]?[0-9]*");

	if (std::regex_match(exchange_rate_string , exchange_rate_pattern) == false)
	{
		std::cout << "Error (data.csv): Exchange Rate Format issue  (f.ex. (+)2.35) => " << exchange_rate_string << std::endl;
		return (1);
	}
	return (0);
}

float		BitcoinExchange::convertAndGetExchangeRate(std::string &exchange_rate_string, std::string &line)
{
	float		exchange_rate;
	
	try
	{
		exchange_rate = stof(exchange_rate_string);
	}
	catch(...)
	{
		std::cout << "Error (data.csv): Could not convert exchange rate to float from line => " << line << std::endl;
		return (-1);
	}

	if (exchange_rate < 0)						//Exchange rate can't be negative.
	{
		std::cout << "Error (data.csv): Exchange Rate value is negative from line => " << line << std::endl;
		return (-1);
	}
	return (exchange_rate);
}

/*
	a. Finds from line
		i. date
		ii. exchange_rate_string
	b. Checks
		i. date
		ii. exchange_rate_string
	c. Converts string (exchange rate) to float
	d. Stores both values in map
*/
void	BitcoinExchange::getDateAndExchangeRate(std::string &line)
{
	std::string		date;
	std::string		exchange_rate_string;
	float			exchange_rate;

	size_t			delimiter;

	delimiter = line.find(",");
	if (delimiter == std::string::npos)
	{
		std::cout << "Error (data.csv): No delimiter (,) found in line => " << line <<  std::endl;
		return ;
	}

	date					= line.substr(0, delimiter);
	exchange_rate_string	= line.substr(delimiter + 1);

	if (date == "date")		//Found 1st line ("date,exchange_rate") -> skip
		return ;

	data obj;
	obj.date = date;
	if (checkDate(obj) == 1)
		return ;

	if (checkExchangeRate(exchange_rate_string) == 1)
		return ;

	exchange_rate = convertAndGetExchangeRate(exchange_rate_string, line);
	if (exchange_rate < -0.1)
		return;

	this -> btcExchangeHistory[date] = exchange_rate;		//Add date and exchange rate into Map	
}

/*
	1. opens data.csv
	2. Read line by line
			a. Find Date
				-> store
			b. Find ExchangeRate
				-> store
	
	Stores in std::map.
*/
int		BitcoinExchange::InitDataCSV()
{

	std::ifstream	in("data.csv");
	std::string		line;

	if (in.fail())
	{
		std::cout << "Error: Failed to open data.csv. Is it possibly missing from the directory?" << std::endl;
		return (1);
	}


	while (getline(in, line))
	{
		getDateAndExchangeRate(line);
	}

	if (btcExchangeHistory.size() == 0)
	{
		std::cout << "Error: No entries were imported from data.csv. Is it possibly empty?" << std::endl;
		return (1);
	}

	return (0);
}


/*
	1. Gets Date and Value in line delimited with " | "
	2. Stores in Data obj

	example line = 2012-01-31 | +2.52
*/
int		BitcoinExchange::getDateAndValue(data &obj, std::string &line)
{
	size_t			delim_start;
	std::string		date;
	std::string		value;

	if (line == "")								// Empty Line Found
	{
		std::cout << "Error: Empty line detected" << std::endl;
		return (1);
	}

	delim_start = line.find(" | ");

	if (delim_start == std::string::npos)		// No Delimiter Found
	{
		std::cout << "Error: Missing proper delimiter \" | \" => " << line << std::endl;
		return (1);
	}

	date	= line.substr(0, delim_start);
	value	= line.substr(delim_start + 3);

	if (date == "date")							// Found 1st line "date | value" -> Skip
	{
		return (1);
	}

	obj.date			= date;					//Store values
	obj.value_string	= value;
	
	return (0);
}


/*
	If no errors were printed (for the line), output will be printed. 
	Format Date => Value(bitcoin units) => Total Value (= Value x exchange rate)
	f.ex. 2011-01-03 => 3 = 0.9
*/
void	BitcoinExchange::print(data &obj)
{
	std::cout << obj.date;
	std::cout << " => ";
	std::cout << obj.value_string;
	std::cout << " = ";
	std::cout << obj.total_value;
	std::cout << std::endl;
}

/*
	Total Value = Value x Exchange Rate 
	f.ex. 1.2 = 3 x 0.4
*/
void	BitcoinExchange::calculateTotalValue(data &obj)
{
	obj.total_value = obj.value * obj.exchangeRate;
}

int		BitcoinExchange::dateOutsideOfScope(data &obj)
{
	if (obj.date < "2009-01-02")			//Date precedes BitCoin
	{
		std::cout << "Error: Dear Time Traveler. You have BitCoins before Day Zero. Fix your TimeStamp => " << obj.date << std::endl;
		return 1;
	}

	if (obj.date > "2025-04-01")			//Date in Future
	{
		std::cout << "Error: We're clearly Past The Present In the Future. Check TimeStamp => " << obj.date <<  std::endl;
		return 1;
	}
	return (0);
}

/*
	Find Nearest date (that occurred before in time.)
*/
int		BitcoinExchange::getNearestPreviousExchangeRate(data &obj)
{
	if (dateOutsideOfScope(obj) == 1)
	{
		return (1);
	}

	std::string	nearest_date = "2009-01-02";				//Initialize Date to One Day before The 1st BitCoin was Mined

	for (const auto& entry : this->btcExchangeHistory)
	{
        if (obj.date > entry.first)										//Date must occur before (= be smaller than) reference date (obj.date)
		{
			nearest_date = std::max(nearest_date, entry.first);			//Chooses more recent date (= with greater value)
		}
    }

	if (nearest_date == "2009-01-02")									//a. If did not find a nearest date.
	{
		obj.exchangeRate = 0;
	}
	else																//b. Found a nearest date.
	{
		obj.exchangeRate = btcExchangeHistory[nearest_date];				//Assign Exchange Rate
	}

	return (0);
}

/*
	Uses date to Search for Exchange Rate from Historical data.
	1. If finds date -> Uses corresponding Exchange Rate
	2. Else, Searches for Nearest Previous Date.

	Assigns Exchange Rate to data obj (for use later).
*/
int	BitcoinExchange::getExchangeRate(data &obj)
{
	auto it = this->btcExchangeHistory.find(obj.date);		//Search for Date

	if (it != btcExchangeHistory.end())						//a. Found Exact date (from Historic exchange Rate)
	{
		obj.exchangeRate = it -> second;						//i. Assign Exchange rate
	}
	else													//b. Did not find date
	{
		if (getNearestPreviousExchangeRate(obj) == 1)					//ii. Let's approximate -> Find closest previous date
		{
			return (1);
		}
	}
	return (0);
}

/*
	Convert Value (string) to Float
	Check
		-Value is Not Greater than 1000
*/
int	BitcoinExchange::convertValueToFloat(data &obj)
{
	float value;

	try
	{
		value = stof(obj.value_string);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "The Error: It's tough to be a rich man. [Bitcoin value off the charts!]" << std::endl;
		return (1);
	}

	if (value >= 1000)
	{
		std::cout << "Error: Bitcoin Value cannot be 1000 or greater => " << value <<  std::endl;
		return (1);
	}

	if (value <= 0)	//Do I need this? I think I have this one covered in Regex
	{
		std::cout << "Error: Bitcoin value NOT allowed to be 0 or below => " << value << std::endl;
		return (1);
	}

	obj.value = value;
	return (0);
}

/*
	Check Value with Regex.
*/
int		BitcoinExchange::checkValue(data &obj)
{
	std::regex	value_pattern("[+]?[0-9]+[.]?[0-9]*");		// Acceptable Format (f.ex. (+)2.35)


	if (std::regex_match(obj.value_string, value_pattern) == false)
	{
		std::cout << "Error with Value Format (f.ex. (+)2.35): Your input => " << obj.value_string << std::endl;
		return (1);
	}

	return (0);
}

/*
	If leap year.
	-> Returns true, 
	If not
	-> Returns false.
*/
bool	BitcoinExchange::leapYearCheck(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

/*
	Checks: 
	-valid months
	-valid days
	-day 31 && month
	-day 30 && February
	-day 29 && February && leapyear
*/
int		BitcoinExchange::furtherDateChecks(data &obj)
{
	//DATE:		2011  -  06  -  30
	//INDEX:	0123  4  56  7  89

	int	year	= stoi(obj.date.substr(0, 4));
	int	month	= stoi(obj.date.substr(5, 2));
	int	day		= stoi(obj.date.substr(8, 2));

	if (month < 1 || month > 12)
	{
		std::cout << "Error: Invalid Month. Valid months are 01-12. Check input => " << obj.date << std::endl;
		return (1);
	}

	if (day < 1 || day > 31)
	{
		std::cout << "Error: Invalid Day. Valid days are generally 1-31. Check input => " << obj.date << std::endl;
		return (1);
	}

	if (day == 31 && ((month == 2) || (month == 4) || (month == 6) || (month == 9) || (month == 11)))
	{
		std::cout << "Error: Selected Month doesn't have 31 days. => " << obj.date << std::endl;
		return (1);
	}

	if (day == 30 && month == 2)
	{
		std::cout << "Error: February doesn't have 30 days. => " << obj.date << std::endl;
		return (1);		
	}

	if (day == 29 && month == 2 && leapYearCheck(year) == false)
	{
		std::cout << "Error: February can't have 29 days. (It's not a leap year). => " << obj.date << std::endl;
		return (1);
	}
	return (0);
}

/*
	Checks with Date and Value (strings) with
		i. regex
		ii. Other Checks
*/
int		BitcoinExchange::checkDate(data &obj)
{

	std::regex	date_pattern("[0-9]{4}-[01][0-9]-[0-3][0-9]");	// Format f.ex. 2012-01-28


	if (std::regex_match(obj.date, date_pattern) == false)
	{
		std::cout << "Error with Date Format (f.ex. 2012-01-28): Input => " << obj.date << std::endl;
		return (1);
	}

	if (furtherDateChecks(obj) == 1)
		return (1);

	return (0);
}

/*
	Initialize "zero-like" values.
	(These values differ from real values.)
*/
void	BitcoinExchange::initDefaultValues(data &obj)
{
	obj.date			= "";
	obj.value_string	= "";
	obj.value			= -1.0;
	obj.exchangeRate	= -1.0;
	obj.total_value		= -1.0;
}

/*
	1. Finds and extracts Date and Value from line
	2. Checks
		-Date
		-Value
	3. Converts Value(string) to Value(float)
	4. Finds Exchange Rate that corresponds (closely) to Date
	5. Calculates Total Value of Bitcoin
	6. Prints

	data object stores (extracted and calculated) values.
*/
void	BitcoinExchange::readAndPrint(std::string &line)
{
	data obj;						//Stores values from line for printing

	initDefaultValues(obj);

	if (getDateAndValue(obj, line) == 1)
		return ;
	
	if (checkDate(obj) == 1)
		return ;
	
	if (checkValue(obj) == 1)
		return ;
	
	if (convertValueToFloat(obj) == 1)
		return ;

	if (getExchangeRate(obj) == 1)
		return ;

	calculateTotalValue(obj);

	print(obj);
}

int		BitcoinExchange::IO_Checks(std::string &bitcoin_file, std::ifstream &in)
{

	if (std::filesystem::is_directory(bitcoin_file) == true)
	{
		std::cerr << "Error: Please pass in a file, Not a directory. Your input: " << bitcoin_file << std::endl;
		return (1);
	}

	if (in.fail() == true)
	{
		std::cerr << "Error opening filestream to bitcoin file => " << bitcoin_file <<  std::endl;
		return (1);
	}

	if (in.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: This file appears to be empty: " << bitcoin_file <<  std::endl;
		return (1);		
	}

	return (0);
}

/*
	1. Open File
	2. Line by Line - Extract
*/
int		BitcoinExchange::run(std::string bitcoin_file)
{
	std::ifstream	in(bitcoin_file);
	std::string		line;

	if (IO_Checks(bitcoin_file, in) == 1)
	{
		return (1);
	}

	while(getline(in, line))			//getline returns true/false
	{
		readAndPrint(line);
	}
	return (0);
}
