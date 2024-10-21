

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp" // Add Ice and Cure? Character? -> We'll find out.... -> I think so though.

class IMateriaSource
{
	public:
		/* Orthodox canon */
		virtual					~IMateriaSource() {}

		/* Methods... */
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;

};

#endif
