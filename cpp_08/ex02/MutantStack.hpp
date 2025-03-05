#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack <T>
{
	public:
		MutantStack()
		{

		};
		~MutantStack()
		{
			
		};
		MutantStack(const MutantStack& rhs)
		{
			std::cout << "Copy Constructor" << std::endl;			
			*this = rhs;
		}
		MutantStack&	operator=(const MutantStack& rhs)
		{
			std::cout << "Copy Assignment Operator" << std::endl;			
			if (this != &rhs)
			{
				std::stack<T>::operator=(rhs);
			}
			return (*this);
		}

		typedef typename std::deque<T>::iterator		iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}

};
