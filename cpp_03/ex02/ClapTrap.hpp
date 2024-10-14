
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
	
		/* Orthodox Canon */
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);

		/* Action Functions */
		virtual void	attack(const std::string& target);
				void	takeDamage(unsigned int amount);
				void	beRepaired(unsigned int amount);

	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
};

#endif