
#include "AAnimal.hpp"


/* ----------------------- Orthodox canon ----------------------- */

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal: Constructor" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal: Constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal: Copy Constructor" << std::endl;
	this->type = other.type;
}

AAnimal&	AAnimal::operator=(const AAnimal &other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}
	
	std::cout << "Copy Assignment Operator: AAnimal REPLACES " << other.type << std::endl;
	this->type = other.type;

	return (*this);
}

std::string		AAnimal::getType() const
{
	return (this->type);
}


/* ----------------------- Methods... ----------------------- */

void	AAnimal::makeSound() const
{
	std::cout << "***AAnimal Sound***" << std::endl;
}
