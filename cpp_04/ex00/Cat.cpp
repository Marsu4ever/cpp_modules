
#include "Cat.hpp"


/* ----------------------- Orthodox canon ----------------------- */

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat: Constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor" << std::endl;	
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat: Copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	Animal::operator=(other);

	std::cout << "Copy Assignment Operator: Cat REPLACES " << other.type << std::endl;	

	return (*this);
}


/* ----------------------- Methods... ----------------------- */

void Cat::makeSound() const
{
	std::cout << this->sound << std::endl;
}
