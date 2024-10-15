
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		/* Orthodox canon */
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog& other);

		/* Methods... */
		void makeSound() const override;


		


	private:
		const	std::string 	sound = "woof";
				Brain*			brain;
};

#endif