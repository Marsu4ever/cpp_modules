
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{

}

Weapon::~Weapon()
{
	
}

void				Weapon::setType(std::string weapon_type)
{
	(this->_type) = weapon_type;
}

const std::string&	Weapon::getType() const
{
	return (this->_type);
}
