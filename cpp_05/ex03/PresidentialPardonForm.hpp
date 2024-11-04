
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
								PresidentialPardonForm(const std::string &target);
								~PresidentialPardonForm();
								PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		void 					execute(Bureaucrat const & executor) const override;
};

#endif 
