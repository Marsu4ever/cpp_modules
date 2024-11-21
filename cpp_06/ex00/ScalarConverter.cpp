
#include "ScalarConverter.hpp"

void	print_types(char type, char c, int num_int, float num_float, double num_double, int digit_count)
{
	if (num_int >= 0 && num_int <= 255)
	{
		if (std::isprint(c) == false)
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		else
		{
			std::cout << "char: " << '\'' << c << '\'' <<  std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}

	if (type == 'c' || type == 'i')
	{
		std::cout << "int: " << num_int << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) <<  num_float << "f" << std::endl;
		std::cout << "double: " <<  std::fixed << std::setprecision(1) << num_double <<  std::endl;
	}
	if (type == 'f' || type == 'd')
	{
		if (num_float > static_cast<double>(std::numeric_limits<int>::max())) //Note: Casted into double because int will implicitly cast to float and lose precision.
		{
			std::cout << "int: overflow" << std::endl;
		}
		else if (num_float < std::numeric_limits<int>::min())
		{
			std::cout << "int: underflow" << std::endl;
		}
		else
		{
			std::cout << "int: " << num_int << std::endl;
		}

		if (digit_count <= 6)
		{
			std::cout << "float: " <<  std::fixed << std::setprecision(5) <<  num_float << "f" <<  std::endl;
			std::cout << "double: " <<  std::fixed << std::setprecision(5) <<  num_double <<  std::endl;
		}
		if (digit_count >= 7)
		{
			std::cout << "float: " << std::scientific << std::setprecision(5) <<  num_float << "f" <<  std::endl;
			std::cout << "double: " << std::scientific << std::setprecision(5) <<  num_double <<  std::endl;
		}
	}
}

bool	error_in_user_input(const std::string s, int period_count)
{
	int		sign_count  	= 0;

	for (char c : s)
	{
		if (c == '+' || c == '-')
		{
			sign_count++;
		}
	}

	// i. Empty string
	if (s.empty())
	{
		std::cerr << "Error: Passed in an empty string." << std::endl;
		return (true);
	}

	// ii. Too many signs
	if (sign_count >= 2)
	{
		std::cerr << "Error: Pass in a single sign (+/-) or no sign." << std::endl;
		return (true);
	}

	// iii. Sign not at start
	if (sign_count == 1)
	{
		if (s[0] != '+' && *s.begin() != '-' )
		{
			std::cerr << "Error: Sign is not at start of number." << std::endl;
			return (true);
		}
	}

	//iv. Too many periods
	if (period_count >= 2)
	{
		std::cerr << "Error: Number cannot contain more than one decimal(.)" << std::endl;
		return (true);
	}
	return (false);
}

char	determine_type(const std::string s, int digit_count, int period_count)
{
	int		alphabet_count	= 0;

	for (char c : s)
	{
		if (std::isalpha(c) != false)
		{
			alphabet_count++;
		}
	}

	/* i. Type = pseudoliteral (float/double) */
	if (s == "-inff" || s == "+inff")
	{
		std::cout << "It's a FLOAT!" << std::endl;
		return ('f');
	}
	if (s == "-inf" || s == "+inf" || s == "nan")
	{
		std::cout << "It's a DOUBLE!" << std::endl;
		return ('d');
	}

	/* ii. Type = Char? */
	if (s.length() == 1)
	{
		if (digit_count == 0)
		{
			std::cout << "It's a CHAR!" << std::endl;
			return ('c');
		}
	}

	/* iii. Type = Int/Float/Double ? */ 
	//Exclude all values that are not digits[0-9], f, F, +/- or .
	for (char c : s)
	{
		if (c == '+' || c == '-' || c == '.' || (c >= '0' && c <= '9') ||  c == 'f' || c == 'F' )
		{
			//Do nothing
		}
		else
		{
			std::cerr << "Error: Type could not be determined." << std::endl;
			return ('?');	
		}
	}

	if (digit_count != 0)
	{
		if (period_count == 0 && alphabet_count == 0)
		{
			std::cout << "It's an INT!" << std::endl;
			return ('i');
		}
		if (period_count == 1 && alphabet_count == 0)
		{
			std::cout << "It's a DOUBLE!" << std::endl;
			return ('d');
		}
		if (period_count == 1 && alphabet_count == 1)
		{
			if (s.back() == 'f' || s.back() == 'F')
			{
				std::cout << "It's a FLOAT!" << std::endl;
				return ('f');
			}
		}
	}

	/* iv. Type = no type */ 	
	std::cerr << "Error: Type could not be determined." << std::endl;
	return ('?');
}

void	ScalarConverter::convert(const std::string s)
{
	/* A. Declare and initialize variables*/
	char	type			= '?';

	char	c				= '\0';
	int		num_int			= 0;
	float	num_float		= 0;
	double	num_double		= 0;

	int		digit_count		= 0;
	int		period_count	= 0;
	

	/* B. Count occurences of characters in string */

	// i. digit_count
	for (char c : s)
	{
		if (std::isdigit(c) != false)
		{
			digit_count++;
		}
	}

	// ii. period_count
	for (char c : s)
	{
		if (c == '.')
		{
			period_count++;
		}
	}

	/* C. Checks*/
	if (error_in_user_input(s, period_count) == true)
	{
		return ;
	}

	/* D. Determine type */
	type = determine_type(s, digit_count, period_count);
	if (type == '?')
	{
		return ;
	}

	std::cout << std::endl;

	/* E. ---CAST VALUES--- */
	/* i. CAST - (if CHAR) */ 
	if (type == 'c')
	{
		//Cast into CHAR
		c			= static_cast<char>(s[0]);
		num_int 	= static_cast<int>(c);
		num_float	= static_cast<float>(c);
		num_double 	= static_cast<double>(c);

	}

	/* ii. CAST - (if INT) */
	if (type == 'i')
	{
		try
		{
			//Cast into INT
			num_int		= static_cast<int>(stoi(s));

			c			= static_cast<char>(num_int);
			num_float	= static_cast<float>(num_int);
			num_double	= static_cast<double>(num_int);

		}
		catch (const std::out_of_range& e)
		{
			if (*s.begin() == '-')
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: underflow" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			else
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			return ;
		}
	}

	if (type == 'f')
	{	
		try
		{
			//Cast into FLOAT
			num_float = static_cast<float>(stof(s));

			if (num_float == INFINITY || num_float == -INFINITY)
			{
				throw std::out_of_range("");
			}

			c			= static_cast<char>(num_float);
			num_int		= static_cast<int>(num_float);
			num_double	= static_cast<double>(num_float);

		}
		catch (const std::out_of_range& e)
		{
			if (*s.begin() == '-')
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: underflow" << std::endl;
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			else
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			return ;
		}

	}

	/* iv. CAST - (if DOUBLE) */
	if (type == 'd')
	{
		try
		{
			//Cast into DOUBLE
			num_double = static_cast<double>(stod(s));

			if (std::isnan(num_double) != false)
			{
				throw std::out_of_range("");
			}

			c			= static_cast<char>(num_double);
			num_int		= static_cast<int>(num_double);
			num_float	= static_cast<float>(num_double);

		}
		catch (const std::out_of_range& e)
		{
			if (s == "nan")
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: nan" << std::endl;			
			}
			else if (*s.begin() == '-')
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: underflow" << std::endl;
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			else
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
			return ;
		}
	}
	print_types(type, c, num_int, num_float, num_double, digit_count);
}
