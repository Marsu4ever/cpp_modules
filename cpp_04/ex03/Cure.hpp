
#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public: 
		/* Orthodox canon */
					Cure();
					// Ice(const std::string &type);
					~Cure();
					Cure(const Cure &other);
		const Cure&	operator=(const Cure &other);

		/* Methods... */
		AMateria*			clone() 				const	override;
		void				use(ICharacter& target) 		override;		

	protected:
		

	private:


};

#endif