
#include "AForm.hpp"


/* ---------------------- Orthodox Canonical Form ---------------------- */

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute, std::string target)
	: 	name(name),
		is_signed(false),
		grade_to_sign(grade_to_sign),
		grade_to_execute(grade_to_execute),
		target(target)
{
	if (grade_to_sign <= 0)
		throw AForm::GradeTooHighException();
	if (grade_to_sign >= 151)
		throw AForm::GradeTooLowException();

	if (grade_to_execute <= 0)
		throw AForm::GradeTooHighException();
	if (grade_to_execute >= 151)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{

}

AForm::AForm(const AForm& other)
	: 	name			(other.name),
		is_signed		(other.is_signed),
		grade_to_sign	(other.grade_to_sign),
		grade_to_execute(other.grade_to_execute),
		target			(other.target)
{

}

AForm&	AForm::operator=(const AForm& other)
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

const std::string&		AForm::get_name() const
{
	return (this->name);
}

const bool&				AForm::get_is_signed() const
{
	return (this->is_signed);
}

const int&				AForm::get_grade_to_sign() const
{
	return (this->grade_to_sign);
}

const int&				AForm::get_grade_to_execute() const
{
	return (this->grade_to_execute);
}

const std::string&		AForm::get_target() const
{
	return (this -> target);
}


/* ------------------- Setters ------------------- */

void	AForm::set_is_signed(const bool& is_signed)
{
	this -> is_signed = is_signed;	
}

void	AForm::set_target(const std::string& target)
{
	this -> target = target;
}

/* ------------------- Main functions ------------------- */

void	AForm::beSigned(Bureaucrat& b)
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
		throw AForm::GradeTooLowException();
	}
}


/* ---------------------- Nested Class Methods  ----------------------*/

const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("Exception: Grade TOO HIGH.");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("Exception: Grade TOO LOW.");
}

const char* AForm::FormNotSigned::what() const noexcept
{
	return ("Exception: Form NOT Signed.");
}

/* ---------------------- Free Functions  ----------------------*/

std::ostream& operator<<(std::ostream& o, const AForm& obj)
{
	o << "Form: " << "\n";
	o << "    name:		"			<< obj.get_name() << "\n";
	o << "    isSigned:		" 		<< std::boolalpha << obj.get_is_signed() << "\n";
	o << "    grade_to_sign:	" 	<< obj.get_grade_to_sign() << "\n";
	o << "    grade_to_execute:	"	<< obj.get_grade_to_execute() << "\n";
	return (o);
}
