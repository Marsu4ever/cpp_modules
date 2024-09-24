
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();

		void			set_name(std::string name);
		void			announce( void ) const;

	private:
		std::string		_name;
	
		void			farewell(void) const;
		std::string		get_name(void) const; 
};

Zombie*		zombieHorde( int N, std::string name );

#endif