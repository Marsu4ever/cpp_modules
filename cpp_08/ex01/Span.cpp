
#include "Span.hpp"

Span::Span(unsigned int N) : _maxIntegers(N)
{

}

Span::~Span()
{

}

Span::Span(Span &rhs)
{
	this->_maxIntegers = rhs._maxIntegers;

	for (size_t i = 0; i < rhs._integers.size(); i++)
	{
		this -> _integers.push_back(rhs._integers[i]);
	}
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_integers.clear();
		
		this->_maxIntegers = rhs._maxIntegers;

		for (size_t i = 0; i < rhs._integers.size(); i++)
		{
			this -> _integers.push_back(rhs._integers[i]);
		}
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_integers.size() < _maxIntegers)
	{
		(this->_integers).push_back(number);
	}
	else
	{
		throw std::length_error("Exception: Vector MaxSize reached -> Can't add number.");
	}
}

size_t	Span::shortestSpan()
{
	if (_integers.size() <= 1)
	{
		throw std::logic_error("Exception: Not enough numbers (i.e. 2 or more) (in vector) to calculate Shortest Span.");
	}
	
	std::vector<int> sorted_integers;
	
	sorted_integers = this->_integers;

	std::sort(sorted_integers.begin(), sorted_integers.end());		//sorts in ascending order


	long long	difference;
	long long	smallest_diff =  UINT_MAX;

	for (size_t i = 1; i < sorted_integers.size(); i++)
	{
		difference = static_cast<long long>(sorted_integers[i]) - static_cast<long long>(sorted_integers[i - 1]);
		smallest_diff = std::min(difference, smallest_diff);
	}

	return (static_cast<size_t> (smallest_diff));
}

size_t	Span::longestSpan()
{
	if (_integers.size() <= 1)
	{
		throw std::logic_error("Exception: Not enough numbers (i.e. 2 or more) (in vector) to calculate Longest Span.");
	}

	auto min = std::min_element(this->_integers.begin(), this->_integers.end());
	auto max = std::max_element(this->_integers.begin(), this->_integers.end());

	long long	difference = static_cast<long long>(*max) - static_cast<long long>(*min);	//cast to long long for edge case where difference is greater than INT_MAX

	return (static_cast<size_t>(difference));
}

void	Span::fillUpWithRandomNumbers()
{
	size_t start = _integers.size();

	std::srand(std::time(0));		//seed it
	
	for (size_t i = start; i < _maxIntegers; i++)
	{
		int random_number = std::rand();
		addNumber(random_number);
	}
}
