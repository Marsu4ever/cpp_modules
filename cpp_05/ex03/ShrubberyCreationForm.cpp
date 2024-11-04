
#include "ShrubberyCreationForm.hpp"


/* ---------------- Orthodox Canonical Form ---------------- */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("Shrubbery Creation Form", 145, 137, target)
{
	;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form("Shrubbery Creation Form", 145, 137, other.get_target())
{
	this -> set_is_signed(other.get_is_signed());
}

ShrubberyCreationForm&		ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
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


void	ShrubberyCreationForm ::create_shrubbery_file() const
{
	std::string	file_name;

	/* Create file name */
	file_name = this->get_target() + "_shrubbery";

	/* Open output file stream */
	std::ofstream	out(file_name);

	/* Check if failed to open output filestream */
	if (out.fail() == true)
	{
		throw std::ios_base::failure("Exception: File operation failed");
	}

	/* Print ASCII trees */
	out << "." << std::endl;
	out << "|\\" << std::endl;
	out << "| \\" << std::endl;
	out << "|  \\" << std::endl;
	out << "-----" << std::endl;
	out << "|    \\" << std::endl;
	out << "-------" << std::endl;
	out << "|      \\" << std::endl;
	out << "---------" << std::endl;	
	out << "|        \\" << std::endl;
	out << "----------." << std::endl;
	out << "|" << std::endl;
	out << "|" << std::endl;
	out << "|" << std::endl;
	out << "" << std::endl;



	out << "root/" << std::endl;
	out << "|---project1/" << std::endl;
	out << "|   |---file1.cpp" << std::endl;
	out << "|   |---ClassName.cpp" << std::endl;
	out << "|   |---ClassName.hpp" << std::endl;
	out << "|   |---Makefile" << std::endl;	
	out << "|---project2/" << std::endl;
	out << "|   |---README.md" << std::endl;		
	out << "|---lonely_file.txt" << std::endl;

	out.close();
}

void 	ShrubberyCreationForm :: execute(const Bureaucrat& executor) const
{
	/* Check if form signed */
	if (this -> get_is_signed() == false)
	{
		throw Form::FormNotSigned();
	}

	if (executor.getGrade() <= this -> get_grade_to_execute())
	{
		create_shrubbery_file();
		std::cout << "Created file \"" << this->get_target() <<  "_shrubbery\" in working directory." << std::endl;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}
