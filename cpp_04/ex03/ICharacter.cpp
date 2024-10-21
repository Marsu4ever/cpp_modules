
#include "ICharacter.hpp"


ICharacter::ICharacter()
{
	std::cout << "Constructor: ICharacter" << std::endl;
}

// ICharacter::ICharacter(std::string &name) : name(name)
// {
// 	std::cout << "Constructor: ICharacter" << std::endl;
// }

ICharacter::ICharacter(const ICharacter &other)
{
	std::cout << "Copy Constructor: ICharacter" << std::endl;
	(void)other;
}

const ICharacter&		ICharacter::operator=(const ICharacter &other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: ICharacter: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	std::cout << "Copy Assignment Operator: ICharacter" << std::endl;

	return (*this);
}
