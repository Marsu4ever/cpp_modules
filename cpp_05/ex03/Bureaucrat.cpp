
#include "Bureaucrat.hpp"
#include "Form.hpp"


/* ---------------- Orthodox Canonical Form ---------------- */

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	this -> grade	= other.grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
	{
		std::cerr << "Error: Tried to assign to self" << std::endl;
		return (*this);
	}

	this -> grade	= other.grade;

	return (*this);
}


/* ---------------------- Methods...  ----------------------*/

const std::string&	Bureaucrat::getName() const
{
	return (this -> name);
}

void	Bureaucrat::increaseGrade()
{
	if (getGrade() <= 1)
	{
		throw GradeTooHighException();
	}
	this -> grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (getGrade() >= 150)
	{
		throw GradeTooLowException();
	}	

	this -> grade++;
}

int		Bureaucrat::getGrade()	const
{
	return (this->grade);
}


/* ------------------- Main Methods ------------------- */

void	Bureaucrat::signForm(Form& form)
{
	/* Check if Form Already SIGNED	*/
	if (form.get_is_signed() == true)
	{
		std::cout << this -> getName() << " couldn't sign form \"" << form.get_name();
		std::cout << "\" because Form is ALREADY SIGNED" << std::endl;	
		return ;
	}

	/* Signing will either Succeed or Fail. "Try" it! ;) */
	try
	{
		form.beSigned(*this);
		std::cout << this -> getName() << " signed form \"" << form.get_name() << "\"" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << this -> getName() << " couldn't sign form \"" << form.get_name();
		std::cout << "\" because Bureaucrat's level was TOO LOW" << std::endl;	
	}
}

void	Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.execute(*this);

		/* Print success */
		std::cout << this -> getName() << " executed form \"" << form.get_name() << "\"" << std::endl;
	}
	catch (const Form::FormNotSigned& e)
	{
		std::cerr << e.what() << '\n';

		/* Explicit error message */
		std::cout << this -> getName() << " COULDN'T EXECUTE form \"" << form.get_name() << "\" because it is NOT SIGNED." << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';

		/* Explicit error message */
		std::cout << this -> getName() << " COULDN'T EXECUTE form \"" << form.get_name() << "\" because Bureaucrat's grade was TOO LOW" << std::endl;; 
	}
	catch(const std::ios_base::failure& e)
	{
		std::cerr << e.what() << '\n';
		
		std::cout << this -> getName() << " COULDN'T EXECUTE form \"" << form.get_name() << "\" because file failed to open." << std::endl;
	}
}


/* ---------------------- Nested Class Methods  ----------------------*/

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Exception: Grade Too HIGH. Only Grades 1-150 are accepted.");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Exception: Grade Too LOW. Only Grades 1-150 are accepted.");
}


/* ---------------------- Free Functions  ----------------------*/

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName();
	out << " - grade: ";
	out << b.getGrade();
	return (out);
}
