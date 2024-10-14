
#include "ScavTrap.hpp"


/* ------------------------ Orthodox Canon ------------------------ */

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20), guard_mode(false)
{
	std::cout << "ScavTrap: Constructor: "  << name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20), guard_mode(false)
{
	std::cout << "ScavTrap: Constructor: "  << name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor: "  << name << std::endl;	
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap: Copy Constructor: " << other.name << std::endl;

	this->guard_mode = other.guard_mode;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
	{
		std::cerr << "ScavTrap: Copy Assignment Operator: Error: Tried to copy self - " << other.name << std::endl;
		return (*this);
	}

    std::cout << "ScavTrap: Copy Assignment Operator: " << other.name <<  " REPLACES " << this->name << std::endl;
	ClapTrap::operator=(other);

	this->guard_mode = other.guard_mode;

	return (*this);
}


/* ------------------------ Action Functions ------------------------ */

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << "ScavTrap " << this->name << " is already dead and CANNOT ATTACK " << target << "." << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "ScavTrap " << this->name << " does NOT have enough Energy Points to ATTACK "  << target << "." << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->name << " VIOLENTLY attacks " << target << ", causing " << this->attack_damage << " points of damage!" <<  std::endl;
	this->energy_points--;	
}

void 	ScavTrap::guardGate()
{
	if (this->hit_points == 0)
	{
		std::cout << "ScavTrap " << this->name << " cannot go into Gate Keeper mode because he's DEAD." << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "ScavTrap " << this->name << " cannot go into Gate Keeper mode because he has NO Energy Points." << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode." << std::endl;	

	this->guard_mode = true;
}
