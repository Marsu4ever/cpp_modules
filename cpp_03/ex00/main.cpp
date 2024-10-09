
#include "ClapTrap.hpp"

int main(void)
{
	//Too convoluted... but fun idea.
	ClapTrap	warrior("Warrior");

	// warrior.attack("Archer");
	// warrior.takeDamage(5);
	// warrior.beRepaired(7);
	ClapTrap	Archer("Archer");

	ClapTrap	skin(warrior);
	skin = Archer;
	
	
	// warrior2 = warrior1;


    return (0);
}
