
#include "ClapTrap.hpp"


/*
	Hey there, Esteemed evaluator!

	There are 4 mains added for your convenience!

	They test...

	Attack, Damage, Repair
		1. Basic functionality
		2. Condition -	No Hit points	- (when Dead)
		3. Condition -	No Energy points
	
	4. Copy constructor and copy assignment operator

*/


int main(void)
{
	// 1. Basic functionality

	ClapTrap	machine("Robo");

	machine.attack("Cyborg");
	machine.takeDamage(5);
	machine.beRepaired(7);
	return (0);
}


/* int main(void)
{
	// 2. Condition -	No Hit points	- (when Dead)

	ClapTrap	machine("Robo");

	machine.takeDamage(42);

	machine.beRepaired(1);
	machine.attack("Cyborg");
	machine.takeDamage(1);
	return (0);
} */


/* int main(void)
{
	// 3. Condition -	No Energy points

	ClapTrap	machine("Robo");
	int			i;

	i = 1;
	while(i < 12)
	{
		std::cout << "i: " << i << " - ";
		machine.beRepaired(2);
		i++;
	}

	std::cout << "i: " << i << " - ";
	machine.attack("Cyborg");
	return (0);
} */


/* int main(void)
{
	// 4. Copy constructor and copy assignment operator

	ClapTrap	machine1("Robo1");
	// machine1.takeDamage(10);
	
	std::cout << std::endl;

	ClapTrap	machine2(machine1);
	
	ClapTrap	machine3("Robo3");
	machine3 = machine1;

	std::cout << std::endl;

	// machine1.attack("Cyborg.");
	// machine2.attack("Cyborg.");
	// machine3.attack("Cyborg.");

	std::cout << std::endl;
	return (0);
} */
