
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		/* Orthodox canon */
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat& other);

		/* Methods... */
		void	makeSound() const override;
		void	put_idea(const std::string &idea) const;
		void	print_brain() const;

	private:
		const	std::string		sound = "meow";
				Brain*			brain;

};

#endif