
#pragma once

#include <iostream>
#include <cstddef> // size_t


template <typename T>
void	print(T& a)
{
	std::cout << a << " ";
}


template <typename T>
void	AddOne(T& a)
{
	a = a + 1;
}


template <typename T>
void	DecreaseOne(T& a)
{
	a = a - 1;
}

template <typename T>
void	iter(T* array_address, size_t array_length, void (*func)(T& element))
{
	for (size_t i = 0; i < array_length; i++)
	{
		func(array_address[i]);
	}
}
