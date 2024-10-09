
#include "Fixed.hpp"


/*
	Instructions:
		There are two mains here to Test (if you so wish to).
*/



//		1. Subject Main

/* int	main( void )
{
	
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} */

// 		2. Test Main

int main(void)
{
	Fixed	a(1);
	Fixed	b(2);

	const Fixed c(3);
	const Fixed d(4);

	std::cout << "min:		" << Fixed::min(a, b) << std::endl;
	std::cout << "max:		" << Fixed::max(a, b) << std::endl;

	std::cout << "min(const):	" << Fixed::min(c, d) << std::endl;
	std::cout << "max(const):	" << Fixed::max(c, d) << std::endl;

	Fixed e = c + d;
	std:: cout << "Addition:	e = c + d = " << c << " + " << d << " = " << e << std::endl;
	
	std::cout << "Addition:	c + d = " << c << " + " << d << " = " << c + d << std::endl;	
	std::cout << "Subtraction:	c - d = " << c << " - " << d << " = " << c - d << std::endl;
	std::cout << "Multiplication:	c * d = " << c << " * " << d << " = " << c * d << std::endl;
	std::cout << "Division:	d * c = " << d << " / " << c << " = " << d / c << std::endl;

	if (a == b)
		std::cout << "Comparison:	==: a is equal to b." << std::endl;		
	else
		std::cout << "Comparison:	==: a is NOT equal to b." << std::endl;	

	if (a != b)
		std::cout << "Comparison:	!=: a is NOT equal to b." << std::endl;		
	else
		std::cout << "Comparison:	!=: a is equal to b." << std::endl;	
	
	if (a >= b)
		std::cout << "Comparison:	>=: a is greater (or equal)." << std::endl;
	else
		std::cout << "Comparison:	>=: b is greater (or equal)." << std::endl;

	if (a <= b)
		std::cout << "Comparison:	<=: a is less than (or equal) to b." << std::endl;
	else
		std::cout << "Comparison:	<=: b is less than (or equal) to a." << std::endl;

	std:: cout << "		a = " << a << std::endl;
	std:: cout << "Pre-increment:	++a = " << ++a << std::endl;
	std:: cout << "		a = " << a << std::endl;
	std:: cout << "Post-increment:	a++ = " << a++ << std::endl;
	std:: cout << "		a = " << a << std::endl;

	std:: cout << "Pre-decrement:	--a = " << --a << std::endl;
	std:: cout << "		a = " << a << std::endl;
	std:: cout << "Post-decrement:	a-- = " << a-- << std::endl;
	std:: cout << "		a = " << a << std::endl;

	return (0);
}
