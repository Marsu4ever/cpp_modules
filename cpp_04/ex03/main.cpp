
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"





int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src; 

/* 	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	AMateria *mat = src->createMateria("ice");
	delete (mat);

	delete (src); */


/* 	AMateria* ice1 = new Ice();

	Character player("Jim");

	// ice1.use();

	player.equip(ice1);
	player.use(0, player);
	// player.unequip(0);

	delete (ice1);
 */

/* 	AMateria* ice1 = new Ice();

	Character player1("Jim");

	// ice1.use();

	player1.equip(ice1);

	Character player2(player1);
	std::cout << "player2.getName(): " << player2.getName() << std::endl;
	player2.use(0, player1);
	player2.use(1, player1);
	player2.use(2, player1);
	player2.use(3, player1);
	 */


/* 	AMateria* ice1 = new Ice();
	AMateria* ice2 = new Ice();
	AMateria* ice3 = new Ice();


	Character player1("Jim");
	Character player2("Beaver");

	// ice1.use();

	player1.equip(ice1);
	player1.equip(ice2);

	player2.equip(ice3);	


	player1 = player2;
	
	std::cout << "player1.getName(): " << player1.getName() << std::endl;
	player1.use(0, player2);
	player1.use(1, player2);
	player1.use(2, player2);
	player1.use(3, player2); */




	// Ice a;
	// std::cout << "GetType: " << a.getType() << std::endl;

	// Ice* ice1 = new Ice();
	
	// AMateria *ice2 = ice1->clone();	

	// delete (ice1);
	// delete (ice2);


	// AMateria* ice1 = new Ice();
	// AMateria* ice2 = new Ice();
	// AMateria* ice3 = new Ice();


	// Character player1("Jim");
	// Character player2("Beaver");

	// // ice1.use();

	// player1.equip(ice1);
	// player1.equip(ice2);

	// player2.equip(ice3);	


	// player1 = player2;
	
	// std::cout << "player1.getName(): " << player1.getName() << std::endl;
	// player1.use(0, player2);
	// player1.use(1, player2);
	// player1.use(2, player2);
	// player1.use(3, player2);


	// delete (ice1);



/*
	AMateria* ice1 = new Ice();
	AMateria* ice2 = new Ice();

	Character player("jim");

	player.equip(ice1);
	player.equip(ice2);
	player.equip(ice2);

	player.unequip(1);
	player.equip(ice2);	

	delete (ice1);
	delete (ice2); 
*/

	return (0);
}


/*
	I'm going to have to make some cool destructors.
*/
