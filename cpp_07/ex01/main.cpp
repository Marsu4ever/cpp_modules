
#include "iter.hpp"

int main(void)
{
	int		array1[3] = {1, 2, 3};
	size_t	array_length1 = sizeof(array1) / sizeof(array1[0]);

	std::cout << "INTS" << std::endl;
	iter(array1, array_length1, print);
	std::cout << std::endl;
	std::cout << "++" << std::endl;
	iter(array1, array_length1, AddOne);
	iter(array1, array_length1, print);
	std::cout << std::endl;
	std::cout << "--" << std::endl;
	iter(array1, array_length1, DecreaseOne);
	iter(array1, array_length1, print);
	std::cout << std::endl << std::endl;


	char	array2[3] = {'a', 'b', '5'};
	size_t	array_length2 = sizeof(array2) / sizeof(array2[0]);

	std::cout << "CHARS" << std::endl;
	iter(array2, array_length2, print);
	std::cout << std::endl;
	std::cout << "++" << std::endl;
	iter(array2, array_length2, AddOne);
	iter(array2, array_length2, print);
	std::cout << std::endl << std::endl;

	float	array3[3] = {1.f, 55.1f, 0.456};
	size_t	array_length3 = sizeof(array3) / sizeof(array3[0]);

	std::cout << "FLOATS" << std::endl;
	iter(array3, array_length3, print);
	std::cout << std::endl;
	std::cout << "++" << std::endl;
	iter(array3, array_length3, AddOne);
	iter(array3, array_length3, print);
	std::cout << std::endl << std::endl;

	return (0);
}
