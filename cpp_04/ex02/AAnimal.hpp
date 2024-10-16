
#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <string>
#include <iostream>

class AAnimal
{
	public:
		/* Orthodox canon */
				AAnimal();
				AAnimal(std::string type);
		virtual	~AAnimal();
				AAnimal(const AAnimal &other);
				AAnimal& operator=(const AAnimal &other);

		/* Methods... */
				std::string	getType()	const;
		virtual	void		makeSound() const = 0;

	protected:
		std::string type;
};

#endif