
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		/* Orthodox canon */
			WrongAnimal();
			WrongAnimal(std::string type);
	virtual	~WrongAnimal();
			WrongAnimal(const WrongAnimal &other);
			WrongAnimal& operator=(const WrongAnimal &other);

		/* Methods... */
			std::string	getType() const;
			void		makeSound() const;

	protected:
		std::string type;
};

#endif