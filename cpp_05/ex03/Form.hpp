
#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	public:
		/* Orthodox Canonical Form */
				Form(const std::string& name, int grade_to_sign, int grade_to_execute, std::string target);
		virtual	~Form();
				Form(const Form& other);
		Form&	operator=(const Form& other);

		/* Getters */
		const	std::string&	get_name()				const;
		const	bool&			get_is_signed() 		const;
		const	int&			get_grade_to_sign() 	const;
		const	int&			get_grade_to_execute()	const;
		const	std::string&	get_target()			const;

		/* Setters */
		void		set_is_signed(const bool& is_signed);
		void		set_target(const std::string& target);

		/* Main functions */
				void	beSigned(Bureaucrat& b);
		virtual void	execute(const Bureaucrat& executor) const = 0;

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

		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

	private:
		const	std::string	name;
				bool		is_signed;
		const	int			grade_to_sign;
		const	int			grade_to_execute;
				std::string	target;
};

/* Free Functions */
std::ostream& operator<<(std::ostream& o, const Form& obj);

#endif 
