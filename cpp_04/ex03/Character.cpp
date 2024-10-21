
#include "Character.hpp"
// #include "c"

// Character::Character()
// {
// 	std::cout << "Constructor: Character" << std::endl;
// }

Character::Character(const std::string &name) : ICharacter(), name(name)
{
	std::cout << "Constructor: Character" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = nullptr;
	}
}

Character::~Character()
{
	std::cout << "Destructor: Character" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this -> inventory[i] != nullptr)
		{
			delete(this -> inventory[i]);

			this->inventory[i] = nullptr;
		}
	}

}

Character::Character(const Character &other) : ICharacter(other)
{
	std::cout << "Copy Constructor: Character" << std::endl;
	
	this -> name = other.name;

	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != nullptr)
		{
			this->inventory[i] = other.inventory[i] -> clone();	//cloning Materia (Ice or Cure)
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

	std::cout << "Copy Assignment Operator: Character" << std::endl;

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
			this->inventory[i] = other.inventory[i] -> clone();	//cloning Materia (Ice or Cure)
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
		return ;
	}

	/* 	Self-check	*/
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
		{
			std::cout << "Can't Equip Materia that is already Equiped (Slot " << i << ")." << std::endl;
			return ;
		} 
	}

	/* 	Put into Inventory	*/
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == nullptr)
		{
			inventory[i] = m;//This looks right.

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
	inventory[idx] = nullptr; 	// I have to consider how things are freed. I guess I free the stuff on the floor?
	std::cout << "Unequiped Materia from Slot " << idx << "." << std::endl;
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
