
#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << "Constructor: Amateria" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor: Amateria" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "Copy Constructor: Amateria" << std::endl;

	this->type = other.type; // so don't copy this???
	/*
		-I think this is ok!
	*/
}

const AMateria&		AMateria::operator=(const AMateria &other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: AMateria: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	std::cout << "Copy Assignment Operator: AMateria" << std::endl;

	this->type = other.type;

	return (*this);
}

const std::string&	AMateria::getType() const
{
	return (this->type);
}
