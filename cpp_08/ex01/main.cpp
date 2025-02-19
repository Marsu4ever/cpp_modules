
#include "Span.hpp"


int main(void)
{
	Span a(3);

	a.addNumber(0);
	a.addNumber(2);
	a.addNumber(10);

	std::cout << "a(3)	{0, 2, 10}" << std::endl;
	std::cout << "Shortest span:	" << a.shortestSpan() << std::endl;
	std::cout << "Longest span:	" << a.longestSpan() << std::endl << std::endl;

	std::cout << "b(15)	{100, -100, 1, 0, 42}" << std::endl;
	Span b(15);
	b.addNumber(100);
	b.addNumber(-100);
	b.addNumber(1);
	b.addNumber(0);
	b.addNumber(42);	
	std::cout << "Shortest span:	" << b.shortestSpan() << std::endl;
	std::cout << "Longest span:	" << b.longestSpan() << std::endl << std::endl;

	std::cout << "c(100)	{INT_MAX, 0, INT_MIN}" << std::endl;
	Span c(100);
	c.addNumber(INT_MAX);
	c.addNumber(0);
	c.addNumber(INT_MIN);
	std::cout << "Shortest span:	" << c.shortestSpan() << std::endl;
	std::cout << "Longest span:	" << c.longestSpan() << std::endl << std::endl;	

	return (0);
}



/* int main(void)
{
	Span a(10000);
	
	a.fillUpWithRandomNumbers();
	std::cout << "Shortest span:	" << a.shortestSpan() << std::endl;
	std::cout << "Longest span:	" << a.longestSpan() << std::endl;	
} */


/* int main(void)
{
	Span b(1);
	b.addNumber(42);

	std::cout << "b(1) {42}" << std::endl;
	try
	{
		b.addNumber(10);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
	try
	{
		b.shortestSpan();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl<< std::endl;
	}

	Span c(0);
	std::cout << "c(0) {}" << std::endl;	
	try
	{
		c.longestSpan();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl<< std::endl;
	}	

	return (0);
} */


