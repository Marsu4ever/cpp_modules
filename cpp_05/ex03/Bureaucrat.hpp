
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <fstream>


class Form;

class Bureaucrat
{
	public:
		/* Orthodox Canonical Form */
					Bureaucrat();
					Bureaucrat(const std::string& name, int grade);
					~Bureaucrat();
					Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);

		/* Methods... */
		const std::string&	getName()	const;
		int					getGrade()	const;

		void				increaseGrade();
		void				decreaseGrade();

		/* Main Methods */
		void				signForm(Form& form);
		void				executeForm(Form const & form);

		/* Nested Class Methods */
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

	private:
		const std::string	name;
		int					grade;
};

/* Free Functions */
std::ostream&	operator<<(std::ostream& out, const Bureaucrat& self);

#endif 
