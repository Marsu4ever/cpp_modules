
#include "Zombie.hpp"

/*
	-range based for loop
	-check Ville git hub
	-check
		-negative edgecase - DONE
		-INT MAX edge case - Still to do
		-nullptr edge case - DONE
*/

int main(void)
{
	Zombie	*zombie_array;
	int		N;
	int		i;

	N = 2,

	zombie_array = zombieHorde(N, "jeff");//Consider negative numbers and 0 // alsoo condider empty string

	/*
		-I'm afraid to use INT_MAX
			-try tomorrow
	*/

	/*	Tests	*/

	//zombie_array = zombieHorde(N, "Jill");
	//zombie_array = zombieHorde(N, "");
	//zombie_array = zombieHorde(N, "ABCabc123!#€%&/()=?`^*_:;,.-'¨´+");
	
	//Also, try a negative number e.g. -3

	for (i = 0; i < N; i++)
	{
		zombie_array[i].announce();		
	}
	delete [] zombie_array;
	return (0);
}

