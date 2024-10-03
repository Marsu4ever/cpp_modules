
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public: 
		HumanB(std::string name);
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon&);

	private:
		const std::string	_name;
		const Weapon 		*_weapon;

		const std::string	get_name() const;
};

#endif