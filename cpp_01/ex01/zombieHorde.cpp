
#include "Zombie.hpp"

static void		init_names(Zombie* zombie_array, int N, std::string name)
{
	int	i;

	i = 0;
	while(i < N)
	{
		zombie_array[i].set_name(name);
		i++;
	}
}

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*zombie_array;

	if (N <= 0)
	{
		std::cerr << "Error: Please pass in a number 1 or greater." << std::endl;
		return (nullptr);
	}
	try		//Here we protect against very large INTS that cause an allocation failure. ;)
	{
		zombie_array = new Zombie[N];
	}
	catch(const std::exception& e)	//Always remember to catch your exception. ;)
	{
		std::cerr << e.what() << "::Try a (significantly) smaller number of zombies" << '\n';
		return (nullptr);
	}

	init_names(zombie_array, N, name);
	return (zombie_array);
}
