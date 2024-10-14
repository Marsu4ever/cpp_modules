
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		/* Orthodox Canon */	
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);

		/* Action Functions */
		void	attack(const std::string& target) override;
		void 	guardGate();

	private:
		bool guard_mode;
};

#endif