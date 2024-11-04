
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	bureaucrat("Boss", 1);
	Intern		im_new_here;
	Form*		form;

	std::cout << "\n-----------1. Tests Intern.makeForm---------------\n\n";

	form = im_new_here.makeForm("presidential request", "ze_target");


	std::cout << "\n-----------2. Tests underlying derived class (if not nullptr)---------------\n\n";

	if (form != nullptr)
	{
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
	}
	else
	{
		std::cout << "form is a nullptr" << std::endl;
	}

	delete(form);
	return (0);
}
