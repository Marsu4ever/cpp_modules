
#include "Form.hpp"

int main(void)
{
	//Test 1: Just signing a form - (it's that simple)

	Bureaucrat joe("Joe", 42);
	Form form("F1", 150, 150);

	std::cout << joe << "\n";
	std::cout << form;

	joe.signForm(form);
	std::cout << form;

	return (0);
}

/* int main(void)
{
	//Test 2: Just signing forms of Different Levels

	Bureaucrat	joe("Joe", 42);
	Form		form1("Low Level", 150, 6);
	Form		form2("High Level", 1, 6);
	Form		form3("Same Level", 42, 6);

	joe.signForm(form1);
	std::cout << form1 << "\n";

	joe.signForm(form2);
	std::cout << form2 << "\n";

	joe.signForm(form3);
	std::cout << form3 << "\n";

	joe.signForm(form3);

	return (0);
} */

/* int main(void)
{
	//Test 3: Form level permutations

	Form a("a", 1, 1);
	Form b("b", 150, 1);
	Form c("c", 1, 150);

	try
	{
		Form d("d", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << "d: " << e.what() << std::endl;
	}

	try
	{
		Form e("e", 1, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << "e: " << e.what() << std::endl;
	}


	try
	{
		Form f("f", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << "f: " << e.what() << std::endl;
	}

	try
	{
		Form g("g", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cout << "g: " << e.what() << std::endl;
	}
	return (0);
} */
