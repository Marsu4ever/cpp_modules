
#pragma once

#include <algorithm>	// std::find()
#include <iterator>		// std::distance

#include <iostream>
template <typename T>
int		easyfind(T& container, int findValue)
{
	auto it = std::find(container.begin(), container.end(), findValue);	//find() is an algorithm function
	if (it != container.end())
	{
		int		index = std::distance(container.begin(), it);
		return	(index);
	}
	else				// Value not found.
	{
		return (-1);
	}
}
