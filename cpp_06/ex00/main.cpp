
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Pass in a single argument that is a number or char." << std::endl;
		return (1);
	}

	std::string user_input = argv[1];

	// ScalarConverter::convert("-789012345678901234567890123456789012345678912345678907890123456789012345678901234567890123456789123456789078901234567890123456789012345678901234567891234567890789012345678901234567890123456789012345678912345678907890123456789012345678901234567890123456789123456789078901234567890123456789012345678901234567891234567890.");//Protect for nullptr

	ScalarConverter::convert(user_input);
	return (0);
} 