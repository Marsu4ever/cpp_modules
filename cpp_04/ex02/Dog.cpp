
#include "Dog.hpp"


/* ----------------------- Orthodox canon ----------------------- */

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog: Constructor" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog: Destructor" << std::endl;	
}

Dog::Dog(const Dog &other) : AAnimal(other)
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

	AAnimal::operator=(other);

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

void	Dog::put_idea(const std::string &idea) const
{
	if (this->brain != nullptr)
	{
		this->brain->set_idea(idea);
	}
}

void	Dog::print_brain() const
{
	if (this-> brain != nullptr)
	{
		this -> brain -> print_ideas();
	}
}
