#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>	//isprint
# include <iomanip>	// std::setprecision (std::fixed - also this one?) 
# include <limits>	//max and min INT - fex. std::numeric_limits<int>::max()
# include <cmath>	//INFINITY

class ScalarConverter
{
	public:
		static void convert(const std::string s);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter&	operator=(const ScalarConverter& rhs);
};

#endif 