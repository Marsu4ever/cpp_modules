
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

/*
	INFO:
		These mains test
			i. type
			ii. sound
		
		For
			1. Dog
			2. Cat
			3. Animal
			4. Wrong Cat
			5. Wrong animal

		(There may be some repetition... repetition... repetition)
*/

int main(void)
{
	const Animal* dog = new Dog();

	std::cout << std::endl;

	std::cout << "Type: ";
	std::cout << dog -> getType() << std::endl;
	std::cout << "Sound: ";
	dog -> makeSound();

	std::cout << std::endl;

	delete dog;
	return (0);
}

/* int main(void)
{
	const Cat cat;

	std::cout << std::endl;

	std::cout << "Type: ";
	std::cout << cat.getType() << std::endl;
	std::cout << "Sound: ";
	cat.makeSound();

	std::cout << std::endl;

	return (0);
} */

/* int main(void)
{
	const Animal* animal = new Animal();

	std::cout << std::endl;

	std::cout << "Type: ";
	std::cout << animal -> getType() << std::endl;
	std::cout << "Sound: ";
	animal -> makeSound();

	std::cout << std::endl;

	delete animal;
	return (0);
} */

/* int main(void)
{
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl;

	std::cout << "Type: ";
	std::cout << wrong_cat -> getType() << std::endl;
	std::cout << "Sound: ";
	wrong_cat -> makeSound();

	std::cout << std::endl;

	delete wrong_cat;
	return (0);
} */

/* int main(void)
{
	const WrongAnimal* wrong_animal = new WrongAnimal();

	std::cout << std::endl;

	std::cout << "Type: ";
	std::cout << wrong_animal -> getType() << std::endl;
	std::cout << "Sound: ";
	wrong_animal -> makeSound();

	std::cout << std::endl;

	delete wrong_animal;
	return (0);
} */





