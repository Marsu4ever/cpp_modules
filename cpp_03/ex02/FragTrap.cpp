
#include "FragTrap.hpp"


/* ------------------------ Orthodox Canon ------------------------ */

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30)
{
	std::cout << "FragTrap: Constructor: "  << this->name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap: Constructor: "  << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor: "  << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap: Copy Constructor: "  << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
	{
		std::cerr << "FragTrap: Copy Assignment Operator: Error: Tried to copy self - " << other.name << std::endl;
		return (*this);
	}
	ClapTrap::operator=(other);

    std::cout << "FragTrap: Copy Assignment Operator: " << other.name <<  " REPLACES " << this->name << std::endl;

	return (*this);
}


/* ------------------------ Action Functions ------------------------ */

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants a true-robo High-Five!" << std::endl;
}
