
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>


class ICharacter;		//Forward Declaration

class AMateria
{
	protected:
		std::string		type;
		bool			equipped;

	public:
		/* Orthodox canon */
						AMateria(const std::string &type);
		virtual			~AMateria();
						AMateria(const AMateria &other);
		const AMateria&	operator=(const AMateria &other);


		/* Methods... */

				const std::string&	getType()		const;
				bool				get_equipped()	const;
				void				set_equipped(bool boolean);
		virtual	AMateria*			clone()			const = 0;
		virtual void				use(ICharacter& target) = 0;

};

#endif