
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(std::string zombie_name);
		~Zombie();

	private:
		const std::string	_name;
	
		void				announce( void ) const;
		void				farewell(void) const;
		std::string			get_name(void) const; 
};

Zombie*		newZombie( std::string name );
void		randomChump( std::string name );

#endif