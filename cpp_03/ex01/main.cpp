
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	big_machine("OPTIMUS");

	std::cout << std::endl;

	big_machine.attack("his buggy computer");
	big_machine.beRepaired(1);
	big_machine.takeDamage(5);
	big_machine.guardGate();

	std::cout << std::endl;

	return (0);
}


/* int main(void)
{
	ScavTrap	big_machine("OPTIMUS");

	std::cout << std::endl;

	big_machine.takeDamage(40);
	big_machine.takeDamage(40);
	big_machine.takeDamage(40);
	big_machine.guardGate();

	std::cout << std::endl;

	return (0);
} */

/* int main(void)
{
	ScavTrap	m1("m1");

	std::cout << std::endl;

	ScavTrap	m2(m1);

	std::cout << std::endl;

	ScavTrap	m3("m3");
	m1 = m3;

	std::cout << std::endl;

	return (0);
} */
