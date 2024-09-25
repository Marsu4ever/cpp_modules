
#include <iostream>
#include <string>

int main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string		*stringPTR;
	std::string&	stringREF = brain;

	stringPTR = &brain;

	std::cout << "Memory address:" << std::endl;
	std::cout << "	string variable:		" << &brain << std::endl;
	std::cout << "	stringPTR:			" << stringPTR << std::endl;
	std::cout << "	stringREF:			" << &stringREF << std::endl;

	std::cout << "Value: " << std::endl;
	std::cout << "	string variable:		" << brain << std::endl;
	std::cout << "	pointed to by stringPTR:	" << *stringPTR << std::endl;
	std::cout << "	pointed to by stringREF:	" << stringREF << std::endl;
	
	return (0);
}
