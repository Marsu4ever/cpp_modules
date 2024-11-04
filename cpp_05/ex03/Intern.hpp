
#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

	public:
		/* Orthodox Canonical Form */
				Intern();
				~Intern();
				Intern(const Intern& other);
		Intern&	operator=(const Intern& other);

		/* Methods... */
		Form* makeForm(std::string form_name, std::string target_form);
};

#endif 