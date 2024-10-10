
#include "Fixed.hpp"


/* --------------special member functions---------------- */

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;

	setRawBits(0);
}

Fixed::Fixed(const int number)
{
	// std::cout << "Int constructor called" << std::endl;

	(this->num) = number*(1 << (this->bits));
}

Fixed::Fixed(const float number)
{
	// std::cout << "Float constructor called" << std::endl;
	
	(this->num) = static_cast<int>(roundf(number*(1 << (this->bits))));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;

	this->num = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;

	if (this == &other)
		return (*this);

	(this->num) = other.getRawBits();

	return (*this);
}


/* ------------------arithmetic operators-------------------- */

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	float result;

	result = this->toFloat() + rhs.toFloat();
	
	Fixed new_obj(result);
	return (new_obj);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	float result;

	result = this->toFloat() - rhs.toFloat();

	Fixed new_obj(result);
	return (new_obj);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	float result;

	result = this->toFloat() * rhs.toFloat();
	
	Fixed new_obj(result);
	return (new_obj);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	float result;

	result = this->toFloat() / rhs.toFloat();
	
	Fixed new_obj(result);
	return (new_obj);
}

/* ------------------comparison operators-------------------- */

bool	Fixed::operator==(const Fixed &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
	{
		return (true);
	}
	else
	{
		return (false);
	}
}


/* --------------increment and decrement operators---------------- */

/* Pre-increment */
Fixed&	Fixed::operator++()
{
	this->num++;
	return (*this);
}

/* Post-increment */
Fixed	Fixed::operator++(int)
{
	Fixed	temp;
	temp = *this;

	this->num++;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->num--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;
	temp = *this;

	this->num--;
	return (temp);
}

/* ---------------------max min functions--------------------- */

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);	
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
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


/* ---------------------free functions----------------------- */

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
