
#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		
		void 		announce(void);//const - add into all functions....
		void 		set_name(std::string);
		std::string get_name(void); 

	private:
		std::string name;
};

Zombie::Zombie()
{

}

Zombie::~Zombie()
{

}


void		Zombie::set_name(std::string input)
{
	this->name = input;
}

std::string 	Zombie::get_name(void)
{
	return (this->name);
}

void	Zombie::announce(void)
{
	std::cout << get_name();
	std::cout << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
	Zombie newZombie;//Do I need a pointer here???
	
	newZombie.set_name("hiiiii");//new
	newZombie.announce();
	return (&newZombie);
}

/*
	-zombie.hpp

	2 functions
		-Zombie* newZombie( std::string name );
		-void randomChump( std::string name );
			-so they are not part of the zombie class???
*/

int main(void)
{
	Zombie z1;


	return (0);
}

/*
	-
*/