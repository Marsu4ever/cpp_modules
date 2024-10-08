
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		/* special member functions */
		Fixed();
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);

		/* member functions */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;
		void	check_max_min_values(int);

	private:
		int					num;
		static const int	bits = 8;

};

/* free functions */
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif