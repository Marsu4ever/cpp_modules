
#include "Fixed.hpp"


/* --------------special member functions---------------- */
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;

	check_max_min_values(number);
	(this->num) = number*(1 << (this->bits));
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;

	(this->num) = static_cast<int>(roundf(number*(1 << (this->bits))));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->num = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &other)
		return (*this);

	(this->num) = other.getRawBits();

	return (*this);
}


/* -----------------member functions------------------- */

int Fixed::getRawBits( void ) const
{
	return (this->num);
}

void	Fixed::setRawBits( int const raw )
{
	(this->num) = raw;
}

int	Fixed::toInt( void ) const
{
	float	decimal;
	int		integer;

	decimal = (static_cast<float>(this->num))/(1<<(this->bits));
	decimal = roundf(decimal);

	integer = static_cast<int>(decimal);
	return (integer);
}

float	Fixed::toFloat( void ) const
{
	float decimal;
	float denominator;
	
	denominator = static_cast<float>(1<<(this->bits));
	decimal = (this->num)/denominator;
	return(decimal);
}

void	Fixed::check_max_min_values(int number)
{
	if (number > 2147483647/(1<<this->bits))
	{
		std::cerr << "Error: Overflow: Try a number that is 8388607 or below" << std::endl;
	}
	else if (number < (-2147483647-1)/(1<<this->bits))
	{
		std::cerr << "Error: Underflow: Try a number that is -8388608 or greater" << std::endl;
	}
}


/* ---------------------free functions----------------------- */

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
