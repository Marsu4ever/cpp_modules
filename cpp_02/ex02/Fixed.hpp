
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

		/*arithmetic operators */
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		/*comparison operators */
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;

		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;

		/* increment and decrement operators */
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		/*max min functions*/
		static Fixed&	max(Fixed &a, Fixed &b);
		static Fixed&	min(Fixed &a, Fixed &b);

		/* member functions */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;



		static const Fixed&	max(const Fixed &a, const Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);

	private:
		int					num;
		static const int	bits = 8;

};

/* free functions */
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif