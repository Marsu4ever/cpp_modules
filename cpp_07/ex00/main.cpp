
/*
	Is it a program?	-> Yes. it has a main.cpp

	swap - Swaps the values of two given arguments. Does not return anything.
	min	- 	Compares the two values passed in its arguments and returns the smallest one.
			If the two of them are equal, then it returns the second one.
	max	-	Compares the two values passed in its arguments and returns the greatest one.
			If the two of them are equal, then it returns the second one.

	can call funcs with any argument
		-arguments HAVE to be SAME type
		-must support ALL comparison operators

	-templates defined in Header file


	int
	char
	double
	float

	string
	Pointers?
	Strange Objects?
*/





/*
	#include <iostream>

	template <typename T>
	T maxValue(T a, T b) {
		return (a > b) ? a : b;
	}

	int main() {
    std::cout << maxValue(5, 10) << std::endl;    // Works with int
    std::cout << maxValue(3.5, 2.1) << std::endl; // Works with double
}
*/

#include "my_first_templates.hpp"
#include <limits> 	//	max float

int main(void)
{
	/* Test 1 */
	std::cout << "*** Test max & min function" << std::endl;
	int a = 3;
	int b = 1;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;	

	std::cout << "max: " << max(a, b) << std::endl;
	std::cout << "min: "<< min(a, b) << std::endl << std::endl;


	/* Test 2 */
	std::cout << "*** Test Swap function" << std::endl;
	::swap( a, b );

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl << std::endl;

	
	/*	Test 3	*/
	std::cout << "*** Testing Floats (another type)" << std::endl;
	float c = std::numeric_limits<float>::max();
	float d = -90000000000.123143;
	
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;	
	std::cout << "max: " << max(c, d) << std::endl;
	std::cout << "min: "<< min(c, d) << std::endl;

	return (0);
}

// int
// main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }