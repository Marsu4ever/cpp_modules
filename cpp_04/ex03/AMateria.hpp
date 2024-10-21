
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>


class ICharacter;		//Forward Declaration

// #include "ICharacter.hpp"

class AMateria
{
	protected:
		//[...]
		std::string		type; 						// should this be const?

	public:
		/* Orthodox canon */
						AMateria(const std::string &type);// Is this one also virtual?
		virtual			~AMateria();
						AMateria(const AMateria &other);
		const AMateria&	operator=(const AMateria &other);
		//[...]


		/* Methods... */

				const std::string&	getType()	const; //Returns the materia type -> Shouldn't this be = 0?
		virtual	AMateria*			clone()		const = 0;
		virtual void				use(ICharacter& target) = 0;

};

#endif