
#include "Cat.hpp"
#include "Dog.hpp"

/*
	upon Construction
		-Brain is made
		(so from Dog and Cat constructors...)
		new Brain()

	Cat and Dog
		private *Brain attribute
	
		private:
			Brain* brain;



	Brain Class
		ideas array
			-100 std::string


	In Main

	Array of Animal objects
		-half dogs
		-half cats


	At End
		-loop over array and delete every Animal
		-delete Dogs and Cats as ANIMALS???


	-animal objects (array)
		-half cats
		-half dogs
			-at end delete as Animals (the dogs abd cats)
		
		-copies cannot be shallow
			-must be deep
*/

Brain::Brain()
{
	std::cout << "Brain: Constructor" << std::endl;	
	ideas[0] = "a";
	ideas[1] = "b";
	ideas[2] = "c";
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
		if (other.ideas[i] != "")
		{
			std:: cout << other.ideas[i] << std::endl;
		}
	}
}

Brain&	Brain::operator=(const Brain& other)
{
if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	/*
		-delete???
	*/

	std::cout << "Copy Assignment Operator: Brain" << std::endl;	
	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}

	return (*this);	
}

void Brain::print_ideas()
{
	int	i;

	i = 0;
	while (i < 100)
	{
		if (this->ideas[i] != "")
		{
			std::cout << this->ideas[i] << std::endl;
		}
		i++;
	}
}



int main(void)
{
	// Brain	a;
	
	// a.ideas[0] = "d";
	// a.ideas[1] = "e";
	// a.ideas[2] = "f";
	// a.print_ideas();

	// Brain b(a);
	// b.print_ideas();



	// Brain c;
	// c.print_ideas();
	// c = a;
	// c.print_ideas();


	// const Animal* cat = new Cat();
	// (void)cat;
	// // const Animal* cat1 = new Cat();


	// delete cat;


	// Cat c1;
	// Cat c2(c1);
	// Cat c3;

	// c3 = c1;
	

	const Animal* array[4] = {new Dog(), new Dog(), new Cat(), new Cat()}; // Try- catch
	(void)array;

	/*
		-tests for deep copies
	*/

	for (int i = 0; i < 4; i++)
	{
		delete array[i];
	}






	// const Animal* dog = new Dog();

	// std::cout << std::endl;

	// std::cout << "Type: ";
	// std::cout << dog -> getType() << std::endl;
	// std::cout << "Sound: ";
	// dog -> makeSound();

	// std::cout << std::endl;

	// delete dog;
	return (0);
}
