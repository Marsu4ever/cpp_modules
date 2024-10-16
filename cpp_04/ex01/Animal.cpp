
#include "Animal.hpp"


/* ----------------------- Orthodox canon ----------------------- */

Animal::Animal() : type("Animal")
{
	std::cout << "Animal: Constructor" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal: Constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal: Copy Constructor" << std::endl;
	this->type = other.type;
}

Animal&	Animal::operator=(const Animal &other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}
	
	std::cout << "Copy Assignment Operator: Animal REPLACES " << other.type << std::endl;
	this->type = other.type;

	return (*this);
}

std::string		Animal::getType() const
{
	return (this->type);
}


/* ----------------------- Methods... ----------------------- */

void	Animal::makeSound() const
{
	std::cout << "***Animal Sound***" << std::endl;
}
