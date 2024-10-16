
#include "Cat.hpp"


/* ----------------------- Orthodox canon ----------------------- */

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat: Constructor" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << "Cat: Destructor" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat: Copy Constructor" << std::endl;

	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	AAnimal::operator=(other);

	std::cout << "Copy Assignment Operator: Cat REPLACES " << other.type << std::endl;	

	delete(this->brain);
	this->brain = new Brain(*other.brain);

	return (*this);
}


/* ----------------------- Methods... ----------------------- */

void	Cat::makeSound() const
{
	std::cout << this->sound << std::endl;
}

void	Cat::put_idea(const std::string &idea) const
{
	if (this->brain != nullptr)
	{
		this->brain->set_idea(idea);
	}
}

void	Cat::print_brain() const
{
	if (this-> brain != nullptr)
	{
		this -> brain -> print_ideas();
	}
}
