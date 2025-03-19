
#include "BitcoinExchange.hpp"

int		check_argument_count(int argc)
{
	if (argc <= 1)
	{
		std::cerr << "Error: Pass in a file containing bitcoin data.\nUse format: \"date | value (0 - 1000)\" (f.ex. 2012-01-31 | 5.2)" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cerr << "Error: Too many arguments. Pass in just One." << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (check_argument_count(argc) != 0)
	{
		return (1);
	}

	BitcoinExchange	btc;

	if (btc.InitDataCSV() != 0)
	{
		return (1);
	}

	if (btc.run(argv[1]) != 0)
	{
		return (1);
	}
	return (0);
}
