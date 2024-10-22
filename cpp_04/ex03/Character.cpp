
#include "Character.hpp"

Character::Character(const std::string &name) : name(name)
{
	// std::cout << "Constructor: Character" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = nullptr;
	}
}

Character::~Character()
{
	// std::cout << "Destructor: Character" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this -> inventory[i] != nullptr)
		{
			delete(this -> inventory[i]);

			this->inventory[i] = nullptr;
		}
	}

}

Character::Character(const Character &other)
{
	// std::cout << "Copy Constructor: Character" << std::endl;
	
	this -> name = other.name;

	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != nullptr)
		{
			this->inventory[i]				= other.inventory[i] -> clone();//cloning Materia (Ice or Cure)
			this->inventory[i] -> set_equipped(true);
		}
		else
		{
			this->inventory[i] = other.inventory[i]; //Copying nullptr
		}
	}
}

const Character&		Character::operator=(const Character &other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Character: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	// std::cout << "Copy Assignment Operator: Character" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != nullptr)
		{
			delete (this->inventory[i]);
		}
	}

	this -> name = other.name;

	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != nullptr)
		{
			this->inventory[i]				= other.inventory[i] -> clone();	//cloning Materia (Ice or Cure)
			this->inventory[i] -> set_equipped(true);
		}
		else
		{
			this->inventory[i] = other.inventory[i]; //Copying nullptr
		}
	}

	return (*this);
}

const std::string&	Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	/*	nullptr check*/
	if (m == nullptr)
	{
		std::cout << "Can't Equip Materia that is a nullptr." << std::endl;
		return ;
	}

	/* 	Self-check	*/
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
		{
			std::cout << "Can't Equip Materia that is already Equiped by Character (Slot " << i << ")." << std::endl;
			return ;
		}
	}

	/* 	Equipped by another Character - check */
	if (m->get_equipped() == true)
	{
		std::cout << "Can't Equip Materia because it is already equipped by ANOTHER Character." << std::endl;
		return ;
	}

	/* 	Put into Inventory	*/
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == nullptr)
		{
			inventory[i]	= m;
			m -> set_equipped(true);
			break ;
		}
	}

	/* 	Status message	*/
	if (i >= 0 && i <= 3)
	{
		std::cout << "Materia equiped to SLOT " << i << "." << std::endl;
	}
	if (i == 4)
	{
		std::cout << "Inventory Full. Can't equip Materia." << std::endl;
	}

}

void	Character::unequip(int idx)
{
	/* 	Index Range Check	*/
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid Unequip Index. Try a number from 0 to 3." << std::endl;
		return ;
	}

	/* 	Empty Slot Check	*/
	if (inventory[idx] == nullptr)
	{
		std::cout << "Inventory slot " << idx << " is EMPTY. Try another slot."  << std::endl;
		return ;
	}

	/* 	Unequip Materia	*/
	std::cout << "Unequiped Materia from Slot " << idx << "." << std::endl;

	inventory[idx] -> set_equipped(false);
	inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	/* 	Index Range Check	*/
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid Use Index. Try a number from 0 to 3." << std::endl;
		return ;
	}

	/*	Empty Slot Check	*/
	if (inventory[idx] == nullptr)
	{
		std::cout << "Inventory slot " << idx << " is EMPTY. Try another slot."  << std::endl;
		return ;
	}

	/*	Use Materia	*/
	this -> inventory[idx] -> use(target);
}
