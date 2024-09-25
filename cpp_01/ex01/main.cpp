
#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie_array;
	int		N;
	int		i;

	N = 3;
	zombie_array = zombieHorde(N, "Jeff");

	/*	
		1. Try different name-inputs
	*/
		//zombie_array = zombieHorde(N, "Jill");
		//zombie_array = zombieHorde(N, "");
		//zombie_array = zombieHorde(N, "ABCabc123!#€%&/()=?`^*_:;,.-'¨´+");
	/*
		2. Try numbers for N
			i. -3
			ii. 1234567890 (large but not INT_MAX)
	*/

	if (zombie_array == nullptr)
	{
		return (-1);
	}
	for (i = 0; i < N; i++)
	{
		zombie_array[i].announce();
	}
	delete [] zombie_array;
	return (0);
}
