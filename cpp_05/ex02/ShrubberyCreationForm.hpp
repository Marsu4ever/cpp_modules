
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
								ShrubberyCreationForm(const std::string &target);
								~ShrubberyCreationForm();
								ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		void 					execute(Bureaucrat const & executor) const override;
		void					create_shrubbery_file() const;
};


#endif 
