
#include "easyfind.hpp"

#include <array>
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
	std::array<int, 3> array = {0, 1, 2};

	std::cout << "Array {0, 1, 2}" << std::endl;
	std::cout << "find 0 -> " << easyfind(array, 0) << std::endl;
	std::cout << "find 1 -> " << easyfind(array, 1) << std::endl;
	std::cout << "find 2 -> " << easyfind(array, 2) << std::endl;
	std::cout << "find 3 -> " << easyfind(array, 3) << std::endl << std::endl;


	std::vector<int> vector = {0, 10, 20};

	std::cout << "Vector {0, 10, 20}" << std::endl;
	std::cout << "find 10 -> " << easyfind(vector, 10) << std::endl;
	std::cout << "find 20 -> " << easyfind(vector, 20) << std::endl;
	std::cout << "find 30 -> " << easyfind(vector, 30) << std::endl << std::endl;	


	std::list<int> lst = {200, 100, 100, 25, -25};

	std::cout << "List {200, 100, 100, 25, -25}" << std::endl;
	std::cout << "find 200 -> " << easyfind(lst, 200) << std::endl;	
	std::cout << "find 100 -> " << easyfind(lst, 100) << std::endl;
	std::cout << "find -25 -> " << easyfind(lst, -25) << std::endl;	
	std::cout << "find -1 -> " << easyfind(lst, -1) << std::endl;

	return (0);
}
