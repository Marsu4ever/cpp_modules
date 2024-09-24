
#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	farewell();
}

void	Zombie::set_name(std::string name)
{
	(this->_name) = name;
}

std::string		Zombie::get_name(void) const
{
	return (this->_name);
}

void	        Zombie::announce( void ) const
{
	std::cout << get_name();
	std::cout << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	        Zombie::farewell(void) const
{
	std::cout << get_name();
	std::cout << ": ";
	std::cout << "Bye bye human..." << std::endl;
}
