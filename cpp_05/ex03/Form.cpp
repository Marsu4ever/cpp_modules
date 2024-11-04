
#include "Form.hpp"


/* ---------------------- Orthodox Canonical Form ---------------------- */

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute, std::string target)
	: 	name(name),
		is_signed(false),
		grade_to_sign(grade_to_sign),
		grade_to_execute(grade_to_execute),
		target(target)
{
	if (grade_to_sign <= 0)
		throw Form::GradeTooHighException();
	if (grade_to_sign >= 151)
		throw Form::GradeTooLowException();

	if (grade_to_execute <= 0)
		throw Form::GradeTooHighException();
	if (grade_to_execute >= 151)
		throw Form::GradeTooLowException();
}

Form::~Form()
{

}

Form::Form(const Form& other)
	: 	name			(other.name),
		is_signed		(other.is_signed),
		grade_to_sign	(other.grade_to_sign),
		grade_to_execute(other.grade_to_execute),
		target			(other.target)
{

}

Form&	Form::operator=(const Form& other)
{
	if (this == &other)
	{
		std::cerr << "Error: Tried to copy self" << std::endl;
		return (*this);	
	}
	
	this->is_signed = other.is_signed;
	this->target	= other.target;

	return (*this);	
}


/* ------------------- Getters ------------------- */

const std::string&		Form::get_name() const
{
	return (this->name);
}

const bool&				Form::get_is_signed() const
{
	return (this->is_signed);
}

const int&				Form::get_grade_to_sign() const
{
	return (this->grade_to_sign);
}

const int&				Form::get_grade_to_execute() const
{
	return (this->grade_to_execute);
}

const std::string&		Form::get_target() const
{
	return (this -> target);
}


/* ------------------- Setters ------------------- */

void	Form::set_is_signed(const bool& is_signed)
{
	this -> is_signed = is_signed;	
}

void	Form::set_target(const std::string& target)
{
	this -> target = target;
}

/* ------------------- Main functions ------------------- */

void	Form::beSigned(Bureaucrat& b)
{

	/* Check if already signed	*/
	if (this -> is_signed == true)
	{
		return ;
	}

	/* 
		if Bureaucrat's Level Higher or same as Form's Level
			-> sign (f.ex. b <= this)
		if not
			-> do not sign (f.ex. b > this)
		Note: 1 is a higher level than 2
	*/
	if (b.getGrade() <= this->get_grade_to_sign())
	{
		this -> is_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}


/* ---------------------- Nested Class Methods  ----------------------*/

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Exception: Grade TOO HIGH.");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Exception: Grade TOO LOW.");
}

const char* Form::FormNotSigned::what() const noexcept
{
	return ("Exception: Form NOT Signed.");
}

/* ---------------------- Free Functions  ----------------------*/

std::ostream& operator<<(std::ostream& o, const Form& obj)
{
	o << "Form: " << "\n";
	o << "    name:		"			<< obj.get_name() << "\n";
	o << "    isSigned:		" 		<< std::boolalpha << obj.get_is_signed() << "\n";
	o << "    grade_to_sign:	" 	<< obj.get_grade_to_sign() << "\n";
	o << "    grade_to_execute:	"	<< obj.get_grade_to_execute() << "\n";
	return (o);
}
