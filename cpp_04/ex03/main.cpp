
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"


int main(void)
{
	AMateria* ice = new Ice();

	Character player("jim");

	player.equip(ice);
	player.equip(ice);

	std::cout << std::endl;

	player.use(-15, player);
	player.use(3, player);
	player.use(0, player);

	std::cout << std::endl;

	player.unequip(1);
	player.unequip(0);

	delete (ice);

	return (0);
}


/* int main(void)
{
	IMateriaSource* src = new MateriaSource();

	AMateria* 	temp =  src -> createMateria("cure");

	src -> learnMateria(new Cure());
	temp =  src -> createMateria("cure");

	std::cout << std::endl;

	src -> learnMateria(new Ice());
	src -> learnMateria(new Ice());
	src -> learnMateria(new Ice());
	src -> learnMateria(new Ice());
	src -> learnMateria(nullptr);

	delete(temp);
	delete (src);

	return (0);
} */
