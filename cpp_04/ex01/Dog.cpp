
#include "Dog.hpp"


/* ----------------------- Orthodox canon ----------------------- */

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog: Constructor" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog: Destructor" << std::endl;	
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog: Copy Constructor" << std::endl;
	
	this->brain = new Brain(*other.brain);
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

	delete(this->brain);
	this->brain = new Brain(*other.brain);		

	return (*this);
}


/* ----------------------- Methods... ----------------------- */

void Dog::makeSound() const
{
	std::cout << this->sound << std::endl;
}