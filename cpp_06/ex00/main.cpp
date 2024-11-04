
/*

	-slightly more difficult thinking in c++ (abstract)

	-math operations???




	-static method
	-not instantiable...

	-only decimal notation...

	
	Checks
		-for errors
		-for type

	Check for
		1. printable characters 
			(range based)
			32 (space) - 127 ~
				-error!
		
		2. letters (f), digits, sign (+/-),
		3. 



- math operations(+/-/ * / / ),
	"1"
	"1 + 2"
	"0"

	Number of digits...

	string to...
		1. char (single letter)
		2. int	(only digits and (sign))
		3. float (digits, period and (sign), if ends in f)
			+inff
			-inff
			nanf
		4. double (digits, period and (sign))
			+inf 
				1.0/0.0 (if divide by zero)
			-inf
				-1.0/0.0
			nan - Not a Number
				0.0 / 0.0 (zero divided by zero)


	-take divisions???
		-doubles???

	Determine from input


	-sometimes return string...

	-casting???
*/

#include <iostream>
#include <string>
#include <cctype>	//isprint()
#include <exception>

class ScalarConverter
{
	public:
		// static int MyStaticMethod();
		static void convert(const std::string number);

	private:
		ScalarConverter();
		//Add Canonical form... I suppose I don't need anything fancy here.
};

void ScalarConverter::convert(std::string number)
{
	/*
		1. Handle Special Cases
			-FOR SCIENCE!
		2. Check input errors
			a. if printable
			b. whitelisted characters (-letters, digits, sign, period)

				is char == YES
					-only one letter?
						Yes
							-> Is char
						No
							-> Error	
					
				is Char == No
				c. Must contain at least one digit
				d. Only one period allowed
				e. Only one sign allowed AND must be at Start
				f. Letter
					-only one
					-is f
					-is at end

		3. Figure out type
		4. Convert to other types
		5. Print
	*/

	/* Check input errors */

	//Check for non-printable characters - ASCII 0 - 31
	for (const char c : number)
	{
		if (std::isprint(c) == false)
		{
			std::cerr << "Error: Input cannot contain non-printable characters." << std::endl;
			return ;
		}
	}

	/* Check special cases */
	/*
		INSERT CODE HERE
	*/




	/* Must contain at least one digit */
	int i = 0;
	for (const char c : number)
	{
		int i = 0;
		if (std::isdigit(c) == true)
		{
			i++;
			return ;
		}
	}
	if (i == 0)
	{
		std::cerr << "Error: Number must contain at least one digit." << std::endl;
		return ;
	}


	for (const char c : number)
	{
		if (std::isdigit(c) == true || std::isalpha(c) == true)
		{
			std::cerr << "Error: Input can only contain digits, letters, sign and period." << std::endl;
			return ;
		}
	}	


	/*
		Allowed characters
			-letters
			-digits
			-sign
			-period 
	*/

	/*
		Further checks
			Period
				-only a single period allowed
			Sign
				-sign only at start
				-only a single sign allowed
				-s
			Letters
				-letter
					-single + start
				-letter
					-at end and must have digits

			Handle Specific case (at start)
				inf
				+inf
				nan
	
				-inff
				+inff
				nanf

	*/


	
	std::cout << "hi" << std::endl;
}
int main(void)
{
	// ScalarConverter::convert(nullptr); // will fail
	// ScalarConverter::convert(0);  // will fail
	//		ScalarConverter::convert("\n"); -> non-printable...
	//		ScalarConverter::convert("\t");




	//empty string??? check??

	//passing in a number makes it exception
		//try catch???
	
	// ScalarConverter a;
	// (void)a;
	// a.convert();
	std::string literal = "3.2";
	
	double value = std::strtod(literal.c_str(), nullptr);

	std::cout << "value: " << value << std::endl;
/* 	try
	{
		ScalarConverter::convert("");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
 */
	return (0);
}

