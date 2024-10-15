
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		/* Orthodox canon */
				Animal();
				Animal(std::string type);
		virtual	~Animal();
				Animal(const Animal &other);
				Animal& operator=(const Animal &other);

		/* Methods... */
				std::string	getType()	const;
		virtual	void		makeSound() const;

	protected:
		std::string type;
};

#endif