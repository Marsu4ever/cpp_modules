
#include <string>
#include <iostream>


/*
	Notes
		
		
*/

//Bureaucrat::GradeTooHighException

//Bureaucrat::GradeTooLowException

class Bureaucrat
{
	public:
		/* Orthodox Canonical Form */
							Bureaucrat();
							Bureaucrat(const std::string& name, int grade);
							~Bureaucrat();
							Bureaucrat(const Bureaucrat& other);
		const Bureaucrat&	operator=(const Bureaucrat& other);

		/*Methods... */
		const std::string&	getName()	const;
		int					getGrade()	const;

		void				increment();
		void				decrement();

		//overload << insertion

	private:
		const std::string	name;
		int					grade; 	//[1-150] [high-low]
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& self);




Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	// std::cout << "(default) Constructor: Bureaucrat" << std::endl;
	
	/*
		-print out details?
	*/
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade)
{
	// std::cout << "(parameterized) Constructor: Bureaucrat" << std::endl;
	if (grade < 1)
	{
		;
	}
	if (grade > 150)
	{
		;
	}
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Destructor: Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	// std::cout << "Copy Constructor: Bureaucrat" << std::endl;
	
	this -> grade	= other.grade;
}

const Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
	{
		std::cerr << "Error: Tried to assign to self" << std::endl;
		return (*this);
	}
	// std::cout << "Copy Assignment Operator: Bureaucrat" << std::endl;

	this -> grade	= other.grade;

	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (this -> name);
}

void	Bureaucrat::increment()
{
	this -> grade--;
}

void	Bureaucrat::decrement()
{
	this -> grade++;
}

int		Bureaucrat::getGrade()	const
{
	return (this->grade);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName();
	out << " - grade: ";
	out << b.getGrade();
	return (out);
}

int main(void)
{
	Bureaucrat bill("bill", 10);
	bill.increment();
	
	std::cout << bill.getGrade() << std::endl;
	
	bill.decrement();

	std::cout << bill.getGrade() << std::endl;

	std::cout << bill<< std::endl;

	return (0);
}
