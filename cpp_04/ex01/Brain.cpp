
#include "Brain.hpp"


/* ----------------------- Orthodox canon ----------------------- */

Brain::Brain()
{
	std::cout << "Brain: Constructor" << std::endl;	
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain: Copy Constructor" << std::endl;	

	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& other)
{
if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	std::cout << "Copy Assignment Operator: Brain" << std::endl;	
	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}

	return (*this);	
}


/* ----------------------- Methods... ----------------------- */

void Brain::print_ideas()
{
	int	i;

	i = 0;
	while (i < 100)
	{
		if (this->ideas[i] != "")
		{
			std::cout << "Idea: " << i + 1 << ": ";
			std::cout << this->ideas[i] << std::endl;
		}
		else
		{
			break ;
		}
		i++;
	}
	if (i == 0) 
	{
		std::cout << "My Brain Doesn't have any ideas. :)" << std::endl;
	}
}

void Brain::set_idea(const std::string &idea)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (ideas[i] == "")
		{
			ideas[i] = idea;
			break ;
		}
	}
	if (i == 100)
	{
		std::cout << "Brain is full" << std::endl;
	}
}
