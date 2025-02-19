
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>	//std::except

#include <algorithm>	//std::sort()
#include <ctime>		//std::time()

#include <climits> 		// UINT_MAX

class Span
{
	private:
		std::vector<int>	_integers;
		unsigned int		_maxIntegers;

	public:
		Span(unsigned int N);
		~Span();
		Span(Span &rhs);
		Span&	operator=(const Span& rhs);

		void	addNumber(int number);
		size_t	shortestSpan();
		size_t	longestSpan();

		void	fillUpWithRandomNumbers();
};
