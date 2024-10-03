
#include "Harl.hpp"

void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	typedef void (Harl::*func_ptr)(void);

	func_ptr function[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i;
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			break ;
		}
	}
	if (i == 4)
		return ;
	(this->*function[i])();
}

void Harl::debug( void )
{
	std::cout << "DEBUG: Let me tell you sumthing." << std::endl;
}

void Harl::info( void )
{
	std::cout << "INFO: I have a lot more to say." << std::endl;
}

void Harl::warning( void )
{
	std::cout << "WARNING: I am being a very angry customer. Take me serious." << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR: This is unacceptable." << std::endl;
}
