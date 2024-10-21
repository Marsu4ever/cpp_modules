
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Constructor: Ice" << std::endl;
}

// Ice::Ice(const std::string &type) : AMateria(type)
// {
// 	std::cout << "(Parameterized) Constructor: Ice" << std::endl;
// }

Ice::~Ice()
{
	std::cout << "Destructor: Ice" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) //This copying is ok. since this didn't exist.
{
	std::cout << "Copy Constructor: Ice" << std::endl;
	/*
		-copy data
			-materia doesn't have state that changes...
				->So this is fine.
	*/
}

const Ice&	Ice::operator=(const Ice &other)
{

	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	std::cout << "Copy Assignment Operator: Ice" << std::endl;
	// AMateria::operator=(other); // No need to copy anything. Because Materia are the same. 

	return (*this);
}

AMateria*	Ice::clone() const
{
	/*
		-call copy constructor???
		-new?
		-typecasting???
			-dynamic cast
	*/

	/*
		-use copy constructor
	*/

	/*
		1. Should this function be able to copy an Ice object typecasted to an AMateria object
			->maybe
		2. Should this function be able to copy AMateria?
			-> probably not 
	*/

	AMateria *ptr = new Ice(*this);
	
	return (ptr);//Change later... I'm pretty sure I don't need to!
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
