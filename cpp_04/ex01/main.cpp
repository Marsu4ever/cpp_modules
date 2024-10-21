
#include "Cat.hpp"
#include "Dog.hpp"

/* int main(void)
{
	//Test constructors and destructors
	Animal*	a = new Cat();
	delete a;

	return (0);
} */

/* int main(void)
{
	//Test 1 - Put ideas and Print ideas
	Cat*	cat = new Cat();

	cat->put_idea("Cats");
	cat->put_idea("Want");
	cat->put_idea("Food!");

	std::cout << std::endl;

	cat -> print_brain();

	std::cout << std::endl;

	delete cat;

	return (0);
} */

/* int main(void)
{
	//Test 2 - Deep Copying a Cat and its Ideas
	Cat*	cat1 = new Cat();
	Cat*	cat2 = new Cat();	

	cat1->put_idea("I'm");
	cat1->put_idea("HHUNGRY!");

	std::cout << std::endl;
	cat1 -> print_brain();
	std::cout << std::endl;

	*cat2 = *cat1;
	cat1 -> put_idea("I'm the First Cat!");
	cat2 -> put_idea("I'm the Second Cat!");

	std::cout << std::endl;
	cat2 -> print_brain();
	std::cout << std::endl;

	delete cat1;
	delete cat2;

	return (0);
} */

/* int main(void)
{
	//Deep copies with Copy Constructor 
	Cat*	cat1 = new Cat();

	cat1->put_idea("I'm");
	cat1->put_idea("HHUNGRY!");

	std::cout << std::endl;
	cat1 -> print_brain();
	std::cout << std::endl;

	Cat cat2(*cat1);

	std::cout << std::endl;
	cat1->put_idea("not prrrrrrrrrrrr");
	cat2.put_idea("prrrrrrrrrrrr");

	cat2.print_brain();
	std::cout << std::endl;

	delete cat1;

	return (0);
} */

int main(void)
{
	// Test 3 - Array test 

	const Animal* array[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

	const Dog* dog = dynamic_cast<const Dog *>(array[0]);

	dog->put_idea("I'm a dog!");
	dog->put_idea("It's true.");

	std::cout << std::endl;
	dog->print_brain();
	std::cout << std::endl;

	const Cat* cat = dynamic_cast<const Cat *>(array[2]);
	
	cat->put_idea("Cats like to climb trees.");
	cat->print_brain();
	
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete array[i];
	}

	return (0);
}
