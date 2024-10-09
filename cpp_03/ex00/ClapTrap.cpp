
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << "Constructor: " << name << std::endl;//Add clap trap in Print???
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor: " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	std::cout << "Copy Constructor: " << other.name << std::endl;

	this->name			= other.name;
	this->hit_points 	= other.hit_points;
	this->energy_points	= other.energy_points;
	this->attack_damage	= other.attack_damage;
}

ClapTrap& ClapTrap::operator=(ClapTrap &other)
{
	
	if (this == &other)
	{
		std::cout << "Copy Assignment Operator: Error: Tried to copy self - " << other.name << std::endl;
		return (other);
	}

	std::cout << "Copy Assignment Operator: " << other.name <<  " --> " << this->name << std::endl;
	this->name			= other.name;
	this->hit_points 	= other.hit_points;
	this->energy_points	= other.energy_points;
	this->attack_damage	= other.attack_damage;
	
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << "Not enough Hit Points to Attack." << std::endl;
		return ;
	}	
	if (this->energy_points == 0)
	{
		std::cout << "Not enough Energy Points to Attack." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage." <<  std::endl;
	this->energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
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
		std::cout << "Not enough Hit Points to be Repaired." << std::endl;
		return ;
	}	
	if (this->energy_points == 0)
	{
		std::cout << "Not enough Energy Points to be Repaired." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " repairs "<< amount << " hit points." <<  std::endl;
	
	this->hit_points += amount;
	this->energy_points--;
}
