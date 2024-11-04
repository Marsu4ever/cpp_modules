
#include "Bureaucrat.hpp"


/* ---------------- Orthodox Canonical Form ---------------- */

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "(default) Constructor: Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade)
{
	std::cout << "(parameterized) Constructor: Bureaucrat" << std::endl;
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
	std::cout << "Destructor: Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	std::cout << "Copy Constructor: Bureaucrat" << std::endl;
	
	this -> grade	= other.grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
	{
		std::cerr << "Error: Tried to assign to self" << std::endl;
		return (*this);
	}
	std::cout << "Copy Assignment Operator: Bureaucrat" << std::endl;

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
