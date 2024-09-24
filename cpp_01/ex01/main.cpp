
#include "Zombie.hpp"

static void		init_names(Zombie* zombie_array, int N, std::string name)
{
	int	i;

	i = 0;
	while(i < N)
	{
		zombie_array[i].set_and_announce_name(name);
		i++;
	}
	/*
		-range-based for loop
	*/
/* 	for (Zombie *&c: zombie_array)
	{

	} */
}

Zombie*	zombieHorde( int N, std::string name )//Null protect string...
{
	Zombie	*zombie_array;

	/* if (N = 0) */

	zombie_array = new Zombie[N];
	init_names(zombie_array, N, name);
	return (zombie_array);
}

int main(void)
{
	Zombie	*zombie_array;

	// delete (zombie_2);
	zombie_array = zombieHorde(1, "QWERTY");//Consider negative numbers and 0 // alsoo condider empty string
	
	// delete [] zombie_array;

	return (0);
}

/*
	-range based for loop
	-check Ville git hub
	-check
		-negative edgecase
		-INT MAX edge case
		-nullptr edge case

*/