
#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr)
{

}

HumanB::~HumanB()
{

}

const std::string HumanB::get_name() const
{
	return (this->_name);
}

void HumanB::attack() const
{
	std::cout << get_name();
	std::cout << " attacks with their ";
	if (_weapon == nullptr)
	{
		std::cout << "bare hands";
	}
	else
	{
		std::cout << this->_weapon->getType();
	}
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	(this->_weapon) = &weapon;
}
