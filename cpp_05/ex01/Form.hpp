
#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	public:
		/* Orthodox Canonical Form */
				Form(const std::string& name, int grade_to_sign, int grade_to_execute);
				~Form();
				Form(const Form& other);
		Form&	operator=(const Form& other);

		/* Getters */
		const	std::string&	get_name()				const;
		const	bool&			get_is_signed() 		const;
		const	int&			get_grade_to_sign() 	const;
		const	int&			get_grade_to_execute()	const;

		/* Main functions */
		void	beSigned(Bureaucrat& b);

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
		const	std::string	name;
				bool		is_signed;
		const	int			grade_to_sign;
		const	int			grade_to_execute;
};

/* Free Functions */
std::ostream& operator<<(std::ostream& o, const Form& obj);

#endif 
