
#include "PresidentialPardonForm.hpp"


/* ---------------- Orthodox Canonical Form ---------------- */

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("Presidential Pardon Form", 25, 5, target)
{
	;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form("Presidential Pardon Form", 25, 5, other.get_target())
{
	this -> set_is_signed(other.get_is_signed());
}

PresidentialPardonForm&		PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
	{
		std::cerr << "Error: Tried to assign to self" << std::endl;
		return (*this);
	}

	this -> set_is_signed(other.get_is_signed());
	this -> set_target(other.get_target());

	return (*this);	
}


/* ---------------------- Methods...  ----------------------*/

void 	PresidentialPardonForm :: execute(const Bureaucrat& executor) const
{
	/* Check if form signed */
	if (this -> get_is_signed() == false)
	{
		throw Form::FormNotSigned();
	}

	if (executor.getGrade() <= this -> get_grade_to_execute())
	{
		std::cout << this -> get_target() <<  " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}
