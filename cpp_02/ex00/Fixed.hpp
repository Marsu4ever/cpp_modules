
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);				//Copy constructor
		Fixed& operator=(const Fixed &other);	//Copy assignment operator

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					num;
		static const int	bits = 8;
};

#endif