
#pragma once

#include <iostream>
#include <stdexcept>	//std::out_of_range

template <typename T>
class Array
{
	private:
		T*		_array;
		size_t	_size;
	
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array<T>& rhs);

		Array&	operator=(const Array<T>& rhs);
		T&		operator[](unsigned int	i) const;

		size_t size() const;
};

template <typename T>
Array<T>::Array() 
{
	_size = 0;
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	try
	{
		_size = n;
		_array	= new T[n];
		for (unsigned int i = 0; i < n; i++)
		{
			_array[i] = T();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Allocating heap memory failed in Parameterized Constructor. Try a different value." << std::endl;
		_array = nullptr;
		_size = 0;
	}
}

template <typename T>
Array<T>::Array(const Array<T>& rhs)
{
	try
	{
		this->_size = rhs._size;
		this->_array = new T[rhs._size];					//Allocate same array size

		for (unsigned int i = 0; i < rhs._size; i++)		//Copy values
		{
			this -> _array[i] = rhs._array[i];
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Heap memory allocation in copy constructor failed." << '\n';
		_array = nullptr;		//assign nullptr, because calling delete will later cause crash (IOT)
		_size = 0;
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		delete [] this -> _array;		//Delete current array
		this -> _array = nullptr;

		try
		{
			this -> _size = rhs._size;
			this -> _array = new T[rhs._size];

			for (unsigned int i = 0; i < rhs._size; i++)
			{
				this -> _array[i] = rhs._array[i];
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << "Heap memory allocation in copy assignment operator failed." << '\n';
			this -> _array = nullptr;
			this -> _size = 0;
		}
	}
	return (*this);
}

template <typename T>
T&		Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
	{
		throw std::out_of_range("Index in [] operator is out of bounds. Try another value.");
	}
	else
	{
		return (_array[i]);
	}
}

template <typename T>
Array<T>::~Array() 
{
	delete [] _array;
}

template <typename T>
size_t	Array<T>::size() const
{
	return (_size);
}


template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& self)
{
	for (unsigned int i = 0; i < self.size(); i++)
	{
		out << self[i] << " ";
	}
	return out;
}

