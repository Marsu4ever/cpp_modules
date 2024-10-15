
#include "Dog.hpp"


/* ----------------------- Orthodox canon ----------------------- */

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog: Constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor" << std::endl;	
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog: Copy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	Animal::operator=(other);

	std::cout << "Copy Assignment Operator: Dog REPLACES " << other.type << std::endl;	

	return (*this);
}


/* ----------------------- Methods... ----------------------- */

void Dog::makeSound() const
{
	std::cout << this->sound << std::endl;
}
