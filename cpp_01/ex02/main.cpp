/*
	Write a program that contains:
		• A string variable initialized to "HI THIS IS BRAIN".
		• stringPTR: A pointer to the string.
		• stringREF: A reference to the string.
	Your program has to print:
		• The memory address of the string variable.
		• The memory address held by stringPTR.
		• The memory address held by stringREF.
	And then:
		• The value of the string variable.
		• The value pointed to by stringPTR.
		• The value pointed to by stringREF.
	That’s all, no tricks. The goal of this exercise is to demystify references which can
	seem completely new. Although there are some little differences, this is another syntax
	for something you already do: address manipulation.
*/

#include <iostream>
#include <string>

int main(void)
{
	std::string		brain;
	std::string		*stringPTR;
	std::string&	stringREF = brain;

	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;

	std::cout << "Memory address:" << std::endl;
	std::cout << "	string variable:		" << &brain << std::endl;
	std::cout << "	stringPTR:			" << stringPTR << std::endl;/*should this be the same in value as the others???*/
	std::cout << "	stringREF:			" << &stringREF << std::endl;

	std::cout << "Value: " << std::endl;
	std::cout << "	string variable:		" << brain << std::endl;
	std::cout << "	pointed to by stringPTR:	" << *stringPTR << std::endl;
	std::cout << "	pointed to by stringREF:	" << stringREF << std::endl;
	
	return (0);
}

