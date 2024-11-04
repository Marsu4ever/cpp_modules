
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	Bureaucrat bureaucrat1("Joe", 1);
	Bureaucrat bureaucrat2("Newbie", 150);

	std::cout << "\n-------------1. How it works-------------\n\n";

	PresidentialPardonForm form1("Smooth Criminal");
	bureaucrat1.signForm(form1);
	bureaucrat1.executeForm(form1);

	std::cout << "\n-------------2. Newbie bureaucrat tries to execute-------------\n\n";

	bureaucrat2.executeForm(form1);

	std::cout << "\n-------------3. Tries to execute Unsigned form-------------\n\n";

	PresidentialPardonForm form2("I was never signed");
	bureaucrat1.executeForm(form2);

	std::cout << "\n-------------4. Newbie tries to sign-------------\n\n";

	bureaucrat2.signForm(form2);

	return (0);
}

/* int main(void)
{
	Bureaucrat bureaucrat("Joe", 1);
	
	std::cout << "\n-------------1. How it works-------------\n\n";
	RobotomyRequestForm form1("Definitely consenting patient");

	bureaucrat.signForm(form1);
	bureaucrat.executeForm(form1);

	std::cout << "\n-------------2. Tries to execute Unsigned form-------------\n\n";
	RobotomyRequestForm form2("Definitely not signed form");

	bureaucrat.executeForm(form2);

	return (0);
} */

/* int main(void)
{
	// Write command:  ./form | grep "Operation was a SUCCESS" | wc -l

	Bureaucrat bureaucrat("Joe", 1);
	
	std::cout << "\n-------------1. 100 tests to visualize if its 50-50-------------\n\n";
	RobotomyRequestForm form("Coin Flip");

	bureaucrat.signForm(form);

	for (int i = 0; i < 100; i++)
	{
		bureaucrat.executeForm(form);	
	}

	return (0);
} */

/* int main(void)
{
	Bureaucrat bureaucrat("Joe", 1);
	
	std::cout << "\n-------------1. How it works-------------\n\n";
	ShrubberyCreationForm form1("ASCII");

	bureaucrat.signForm(form1);
	bureaucrat.executeForm(form1);

	return (0);
} */
