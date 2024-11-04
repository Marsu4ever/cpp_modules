
#include "Intern.hpp"


/* ---------------------- Orthodox Canonical Form ---------------------- */

Intern::Intern()
{
	;
}

Intern::~Intern()
{
	;
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this == &other)
	{
		std::cerr << "Error: Tried to copy self" << std::endl;
		return (*this);	
	}

	return (*this);	
}


/* ------------------- Methods... ------------------- */

Form*	Intern::makeForm(std::string form_name, std::string target)
{
	std::string form_array[3] = {"presidential request","robotomy request", "shrubbery request"};
	Form*		form;

	int i;

	for (i = 0; i < 3; i++)
	{
		if (form_array[i] == form_name)
		{
			break;
		}
	}
	switch (i)
	{
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		
		case 2: 
			form = new ShrubberyCreationForm(target);
			break;			
		
		default:
			std::cout << "No such form exists. Try Form names: presidential, robotomy or shrubbery request." << std::endl;
			form = nullptr;
	}
	if (form != nullptr)
	{
		std::cout << "Intern creates form: " << form->get_name() << "." << std::endl;		
	}

	return (form);
}
