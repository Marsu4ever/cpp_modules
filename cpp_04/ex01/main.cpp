
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

/* int main(void)
{
	//Test constructors and destructors
	Animal*	a = new Cat();
	delete a;

	return (0);
} */

/* int main(void)
{
	//Test - Put ideas and Print ideas
	Cat*	cat = new Cat();

	cat->put_idea("1");
	cat->put_idea("Want");
	cat->put_idea("Foodie!");

	cat -> print_brain();
	delete cat;

	return (0);
} */

/* int main(void)
{
	//Test - Deep Copying (with assignment operator) a Cat and its Ideas
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
	cat2.put_idea("prrrrrrrrrrrr");

	cat2.print_brain();
	std::cout << std::endl;

	delete cat1;

	return (0);
} */




int main(void)
{
	// Array test 

	const Animal* array[4] = {new Dog(), new Dog(), new Cat(), new Cat()}; // Try- catch

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





	// a.ideas[1] = "d";
	// a.ideas[2] = "e";
	// a.ideas[3] = "f";
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
	
	// const Animal* var = new Dog();



	// delete var;

	// const Animal* array[4] = {new Dog(), new Dog(), new Cat(), new Cat()}; // Try- catch
	// (void)array;

	// /*
	// 	-tests for deep copies
	// */

	// for (int i = 0; i < 4; i++)
	// {
	// 	delete array[i];
	// }






	// const Animal* dog = new Dog();

	// std::cout << std::endl;

	// std::cout << "Type: ";
	// std::cout << dog -> getType() << std::endl;
	// std::cout << "Sound: ";
	// dog -> makeSound();

	// std::cout << std::endl;

	// delete dog;
	// return (0);
}
