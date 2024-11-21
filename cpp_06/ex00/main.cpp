
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Pass in a single argument that is a number or char." << std::endl;
		return (1);
	}

	std::string user_input = argv[1];

	ScalarConverter::convert(user_input);
	return (0);
} 
