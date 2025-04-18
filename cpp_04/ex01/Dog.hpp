
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
		void 	makeSound() const override;
		void	put_idea(const std::string &idea) const;
		void	print_brain() const;

	private:
		const	std::string 	sound = "woof";
				Brain*			brain;

};

#endif