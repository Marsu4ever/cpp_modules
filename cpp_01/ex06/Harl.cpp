
#include "Harl.hpp"

void Harl::complain( std::string level )
{
	// ReturnType (ClassName::*pointerName)(parameterTypes);
//  typedef void (Harl::*fptr)(void);

	typedef void (Harl::*func_ptr)(void);//Why type def???

	// pointerName = &ClassName::MemberFunctionName;
	func_ptr function[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
// fptr functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "ERROR", "INFO", "WARNING"};

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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!"<< std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!"<< std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now. I want to speak to the manager now." << std::endl;
}

