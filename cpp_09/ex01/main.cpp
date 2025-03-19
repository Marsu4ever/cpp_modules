
#include "RPN.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Pass in a single string with a calculation in Reverse Polish Notation (f.ex. 2 3 + 4 *)" << std::endl;
		return (1);
	}


	RPN 	calculator;

	if (calculator.mainProgram(argv[1]) == 1)
	{
		return (1);
	}

	return (0);
}
