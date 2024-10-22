
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Constructor: Ice" << std::endl;
}

Ice::~Ice()
{
	// std::cout << "Destructor: Ice" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	// std::cout << "Copy Constructor: Ice" << std::endl;
}

const Ice&	Ice::operator=(const Ice &other)
{

	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	// std::cout << "Copy Assignment Operator: Ice" << std::endl;

	return (*this);
}

AMateria*	Ice::clone() const
{
	AMateria *ptr = new Ice(*this);
	
	return (ptr);
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<  std::endl;
}
