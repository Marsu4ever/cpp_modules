

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	//--------HumanA-----------

	Weapon club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	return (0);
}

/* int main(void)
{
	//--------HumanB-----------

	Weapon club = Weapon("crude spiked club");
	
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();

	return (0);
} */
