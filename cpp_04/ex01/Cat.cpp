
#include "Cat.hpp"


/* ----------------------- Orthodox canon ----------------------- */

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat: Constructor" << std::endl;
	this->brain = new Brain();			//FOR DOG!!!!!!	//Try-Catch???
}

Cat::~Cat()
{
	delete (this->brain);				//FOR DOG!!!!!!
	std::cout << "Cat: Destructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat: Copy Constructor" << std::endl;

	/*
		-no need for clean up since it's copying here and uninitialized obj
		-copy brain
			-HOW?
	*/
	this->brain = new Brain(*other.brain);				//FOR DOG!!!!!! // If fails???
	
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

	delete(this->brain);								//Is this good?
	this->brain = new Brain(*other.brain);				//Try catch???

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
