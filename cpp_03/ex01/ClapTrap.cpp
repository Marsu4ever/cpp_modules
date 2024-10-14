
#include "ClapTrap.hpp"


/* ------------------------ Orthodox Canon ------------------------ */

ClapTrap::ClapTrap() : name("Default"), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << "Constructor: " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << "ClapTrap: Constructor: " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) : name(name), hit_points(hp), energy_points(ep), attack_damage(ad)
{
	std::cout << "ClapTrap: Constructor: " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap: Copy Constructor: " << other.name << std::endl;

	this->name			= other.name;
	this->hit_points 	= other.hit_points;
	this->energy_points	= other.energy_points;
	this->attack_damage	= other.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
	{
		std::cerr << "ClapTrap: Copy Assignment Operator: Error: Tried to copy self - " << other.name << std::endl;
		return (*this);
	}

	std::cout << "ClapTrap: Copy Assignment Operator: " << other.name <<  " REPLACES " << this->name << std::endl;
	this->name			= other.name;
	this->hit_points 	= other.hit_points;
	this->energy_points	= other.energy_points;
	this->attack_damage	= other.attack_damage;

	return (*this);
}


/* ------------------------ Action Functions ------------------------ */

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead and CANNOT ATTACK " << target << "." << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " does NOT have enough Energy Points to ATTACK "  << target << "." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" <<  std::endl;
	this->energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead and CANNOT take DAMAGE." << std::endl;
		return ;
	}
	
	if (amount >= this->hit_points)
	{
		std::cout << "ClapTrap " << this->name << " takes "<< this->hit_points << " points of damage... And is now DEAD!" <<  std::endl;
		this->hit_points = 0;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " takes "<< amount << " points of damage." <<  std::endl;
	this->hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead and CANNOT be REPAIRED." << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " does NOT have enough Energy Points to be REPAIRED." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " repairs "<< amount << " hit point(s)." <<  std::endl;
	
	this->hit_points += amount;
	this->energy_points--;
}
