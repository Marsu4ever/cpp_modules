
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Constructor: Cure" << std::endl;
}


Cure::~Cure()
{
	// std::cout << "Destructor: Cure" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	// std::cout << "Copy Constructor: Cure" << std::endl;
}

const Cure&		Cure::operator=(const Cure &other)
{

	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	// std::cout << "Copy Assignment Operator: Cure" << std::endl;

	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria *ptr = new Cure(*this);
	
	return (ptr);
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" <<  std::endl;
}
