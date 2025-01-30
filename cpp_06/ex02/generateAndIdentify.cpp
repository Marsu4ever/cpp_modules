
#include "generateAndIdentify.hpp"

Base*	generate(void)
{
	std::srand(std::time(0));  // Seed with current time
    int random_number = std::rand() % 3;
	
	Base *ptr;
	if (random_number == 0)
	{
		ptr = new A();
		std::cout << "gen - A created" << std::endl;
	}
	else if (random_number == 1)
	{
		ptr = new B();
		std::cout << "gen - B created" << std::endl;		
	}
	else
	{
		ptr = new C();
		std::cout << "gen - C created" << std::endl;		
	}
	return (ptr);
}


void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "ptr - It's A!" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "ptr - It's B!" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "ptr - It's C!" << std::endl;
	}
	else
	{
		std::cout << "ptr - Type is very unknown!" << std::endl;
	}
}


void	identify(Base& p)
{
	//Check if A
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "ref - It's A!" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		// std::cerr << e.what() << '\n';
	}

	//Check if B
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "ref - It's B!" << std::endl;
	}
	catch(const std::exception& e){}

	//Check if C
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "ref - It's C!" << std::endl;
	}
	catch(...){}
}
