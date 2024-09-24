
#include "Zombie.hpp"

int main(void)
{
	Zombie	zombie_1("Stacky");
	Zombie	*zombie_2;

	randomChump("Randy");

	zombie_2 = newZombie("Heapy");
	delete (zombie_2);

	return (0);
}
