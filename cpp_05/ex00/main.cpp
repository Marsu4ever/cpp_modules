
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat guy("guy", 2);
	std::cout << guy << std::endl;

	guy.decreaseGrade();
	std::cout << guy << std::endl;

	guy.increaseGrade();
	std::cout << guy << std::endl;

	guy.increaseGrade();
	std::cout << guy << std::endl;

	try
	{
		guy.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << guy << std::endl;

	return (0);
}

/* int main(void)
{

	std::cout << "Noob: \n";
	try
	{
		Bureaucrat noobie("noob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << '\n';


	std::cout << "Mr. OverPowered: \n";
	try
	{
		Bureaucrat op("Mr. OverPowered", 0);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << '\n';



	std::cout << "im_null_name: \n";
	try
	{
		Bureaucrat im_null_name(nullptr, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << '\n';

	return (0);
} */


/* int main(void)
{
	Bureaucrat* lower_guy;
	try
	{
		lower_guy = new Bureaucrat("lower guy", 148);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *lower_guy << std::endl;

	try
	{
		lower_guy->decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *lower_guy << std::endl;

	try
	{
		lower_guy->decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *lower_guy << std::endl;

	try
	{
		lower_guy->decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *lower_guy << std::endl;
	delete (lower_guy);
	return (0);
} */
