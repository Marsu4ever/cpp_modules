
#include "RobotomyRequestForm.hpp"


/* ---------------- Orthodox Canonical Form ---------------- */

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45, target)
{
	;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("Robotomy Request Form", 72, 45, other.get_target())
{
	this -> set_is_signed(other.get_is_signed());
}

RobotomyRequestForm&		RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
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

unsigned int	RobotomyRequestForm :: random_number_generator() const
{
	unsigned int	random_num;
	int64_t			seed_value;

 	seed_value = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed_value);

	random_num = generator();

	return (random_num);
}

void 	RobotomyRequestForm :: execute(const Bureaucrat& executor) const
{
	unsigned int	number;

	/* Check if form signed */
	if (this -> get_is_signed() == false)
	{
		throw AForm::FormNotSigned();
	}

	if (executor.getGrade() <= this -> get_grade_to_execute())
	{
		std::cout << "Drilling has commenced: brrrr BRRRRRRRRRRR" << std::endl;

		number = random_number_generator();
		number = number % 2;

		if (number == 1)
		{
			std::cout << "Robotomy Outcome: " << this->get_target() <<  "'s Operation was a SUCCESS! Robotomies are the Future! 🤖👍" << std::endl;
		}
		else
		{
			std::cout << "Robotomy Outcome: Sooooo... The Operation didn't go as expected... Please plug yourself into this PCP diagnostic package. ⚡" << std::endl;
		}
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}
