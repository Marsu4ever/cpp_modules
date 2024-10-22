
#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public: 
		/* Orthodox canon */
					Ice();
					~Ice();
					Ice(const Ice &other);
		const Ice&	operator=(const Ice &other);

		/* Methods... */
		AMateria*			clone() 				const	override;
		void				use(ICharacter& target) 		override;		

};

#endif