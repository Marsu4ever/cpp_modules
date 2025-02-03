
#include "Array.hpp"

int main(void)
{	
	std::cout << "Default constructor: d()" << std::endl;
	Array<int> d;
	std::cout << "d: " << d << std::endl;	


	std::cout << "Parameterized constructor: a(3)" << std::endl;
	Array<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 5;


	std::cout << "a: " << a << std::endl;

	Array<int> b(5);
	b[0] = 42;
	std::cout << "b: " << b << std::endl;

	std::cout << "Copy Assignment Operator: b = a" << std::endl;
	b = a;
	std::cout << "b: " << b << std::endl;	

	Array<int> c(a);
	std::cout << "Copy Constructor: c(a)" << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "a.size(): " << a.size() << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "a[1]: " << a[1] << std::endl;
	std::cout << "a[2]: " << a[2] << std::endl;

	try 
	{
		std::cout << "a[3]: " << a[3] << std::endl;
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		std::cout << "a[-1]: " << a[-1] << std::endl;
	}
	catch(std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "CHARS: e(3)" << std::endl;
	Array<char> e(3);
	e[0] = 'a';
	e[1] = 42;
	e[2] = 'F';
	std::cout << "e: " << e << std::endl;

	std::cout << "STRINGS: f(2)" << std::endl;
	Array<std::string> f(2);
	f[0] = "hello";
	f[1] = "world";
	std::cout << "f: " << f << std::endl;

	return (0);
}
