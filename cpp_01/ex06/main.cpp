
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Pass in one argument." << std::endl;
		return (1);
	}
	
	std::string input = argv[1];
	int			num;
	Harl		customer;

	num = 0;
	if (input == "DEBUG")
	{
		num = 1;
	}
	if (input == "INFO")
	{
		num = 2;
	}
	if (input == "WARNING")
	{
		num = 3;
	}
	if (input == "ERROR")
	{
		num = 4;
	}
	switch(num)
	{
		case 1:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			customer.complain("DEBUG");
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << "[ INFO ]" << std::endl;
			customer.complain("INFO");
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << "[ WARNING ]" << std::endl;
			customer.complain("WARNING");
			std::cout << std::endl;
		}
		case 4:
		{
			std::cout << "[ ERROR ]" << std::endl;
			customer.complain("ERROR");
			std::cout << std::endl;
		}
		default:
			std::cerr << "Error: Pass in a valid argument (f.ex. DEBUG, INFO, WARNING or ERROR)."<< std::endl;

	}
	return (0);
}
