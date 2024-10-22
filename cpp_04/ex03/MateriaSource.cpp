
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "Constructor: MateriaSource" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		source[i] = nullptr;
	}
}

MateriaSource::~MateriaSource()
{
	// std::cout << "Destructor: MateriaSource" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this -> source[i] != nullptr)
		{
			delete(this -> source[i]);
			this->source[i] = nullptr;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	// std::cout << "Copy Constructor: MateriaSource" << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (other.source[i] != nullptr)
		{
			this->source[i] = other.source[i] -> clone();
			this->source[i] -> set_equipped(false);
		}
		else
		{
			this->source[i] = other.source[i]; //Copying nullptr
		}
	}
}


const MateriaSource&    MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
	{
		std::cerr << "Copy Assignment Operator: Character: Error: Tried to copy self" << std::endl;
		return (*this);
	}

	// std::cout << "Copy Assignment Operator: MateriaSource" << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (this -> source[i] != nullptr)
		{
			delete(this -> source[i]);
			this->source[i] = nullptr;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (other.source[i] != nullptr)
		{
			this->source[i] = other.source[i] -> clone();
			this->source[i] -> set_equipped(false);
		}
		else
		{
			this->source[i] = other.source[i]; //Copying nullptr
		}
	}

	return (*this);
}

void		MateriaSource::learnMateria(AMateria* m_to_learn)
{
	if (m_to_learn == nullptr)
	{
		std::cout << "MateriaSource cannot be learnt since it is nullptr." << std::endl;
		return ;
	}
	
	int i;

	for (i = 0; i < 4; i++)
	{
		if (this->source[i] == nullptr)
		{
			this->source[i] = m_to_learn -> clone();
			std::cout << "Learnt MateriaSource - (" << this->source[i] -> getType() << ")." << std::endl;
			delete (m_to_learn);
			return ;
		}
	}
	
	delete (m_to_learn);

	if (i == 4)
	{
		std::cout << "MateriaSource is Full and Cannot Learn further Materias." << std::endl;
	}

}

AMateria*	MateriaSource::createMateria(const std::string& type)
{

	for (int i = 0; i < 4; i++)
	{
		if (this->source[i] != nullptr)
		{
			if (this->source[i] -> getType() == type)
			{
				std::cout << "Created Material - (" << this->source[i] -> getType() << ")." << std::endl;
				return (this->source[i] -> clone());
			}
		}
	}	

	std::cout << "Could not Find Materia In MateriaSource: " << type << "." << std::endl;
	return (nullptr);
}
 