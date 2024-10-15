
#include "WrongCat.hpp"


/* ----------------------- Orthodox canon ----------------------- */

WrongCat::WrongCat() : WrongAnimal("Wrong Cat")
{
	std::cout << "WrongCat: Constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor" << std::endl;	
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat: Copy Constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	WrongCat::operator=(other);

	std::cout << "Copy Assignment Operator: WrongCat REPLACES " << other.type << std::endl;	

	return (*this);
}


/* ----------------------- Methods... ----------------------- */

void WrongCat::makeSound() const
{
	std::cout << this->sound << std::endl;
}
