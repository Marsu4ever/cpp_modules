
#include "WrongAnimal.hpp"


/* ----------------------- Orthodox canon ----------------------- */

WrongAnimal::WrongAnimal() : type("Wrong Animal")
{
	std::cout << "WrongAnimal: Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal: Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}
	
	std::cout << "Copy Assignment Operator: WrongAnimal REPLACES " << other.type << std::endl;
	this->type = other.type;

	return (*this);
}

std::string     WrongAnimal::getType() const
{
	return (this->type);
}


/* ----------------------- Methods... ----------------------- */

void     WrongAnimal::makeSound() const
{
	std::cout << "***WRONG Animal Sound***" << std::endl;
}
