
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

// # include "AMateria.hpp"
# include "ICharacter.hpp"		//Comment out...

class Character : public ICharacter
{
	public:
		/* Orthodox canon */
							// Character();
							Character(const std::string &name);
							~Character();                           //Probably don't need virtual here...
							Character(const Character &other);
		const Character&	operator=(const Character &other);

		/* Methods... */
		const std::string&	getName() const override;
		void				equip(AMateria* m) override;
		void				unequip(int idx) override;
		void				use(int idx, ICharacter& target) override;    //Use ICharacter here?

	private:
		std::string			name;
		AMateria*			inventory[4];

};

#endif