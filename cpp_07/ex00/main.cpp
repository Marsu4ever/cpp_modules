
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
