
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		/* Orthodox canon */
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat& operator=(const WrongCat& other);

		/* Methods... */
		void makeSound() const;

	private:
		const std::string sound = "WRONG meow";

};

#endif