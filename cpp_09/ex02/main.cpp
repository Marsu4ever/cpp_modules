#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe	data;
	int			i;
	
	if (argc == 1)
	{
		std::cerr << "Error: Pass in positive integers to be sorted" << std::endl;
		return (1);
	}

	for (i = 1; argv[i] != nullptr; i++)
	{
		if (data.addNumber(argv[i]) == 1)
			return (1);
	}

	if (data.duplicatesCheck() == 1)
	{
		return (1);
	}

	data.vecSort();
	data.dequeSort();
	data.print(argv);

	return (0);
}
