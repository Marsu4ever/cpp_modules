
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		/* Orthodox canon */
								MateriaSource();
								~MateriaSource();
								MateriaSource(const MateriaSource &other);
		const MateriaSource&	operator=(const MateriaSource &other);                      

		/* Methods... */
		void		learnMateria(AMateria*)                 override;
		AMateria*	createMateria(std::string const & type) override;

	private:
		AMateria*			source[4];//Private?
};

#endif

