
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <chrono>	//pseudo -random seed generator
#include <random>	//random number generator
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
								RobotomyRequestForm(const std::string &target);
								~RobotomyRequestForm();
								RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		void 					execute(Bureaucrat const & executor) const override;
		unsigned int			random_number_generator() const;
};

#endif 
