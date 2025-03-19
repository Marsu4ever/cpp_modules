
#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{
	
}

RPN::RPN(const RPN &other) : stack(other.stack)
{

}

const RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this -> stack = other.stack;	
	}
	return (*this);
}

/*
	Checks if string...
	i. is empty
	ii. start with empty space
	iii. contains only characters 0-9, +, -, *, / and spaces.
*/
int		RPN::checks(std::string input)
{
	if (input == "")
	{
		std::cerr << "Error: Empty String Passed. => It should be a calculation." << input << std::endl;
		return (1);
	}

	if (input[0] == ' ')
	{
		std::cerr << "Error: String can't start with a space. -> Instead, pass in a single digit (0-9)" << std::endl;
		return (1);
	}

	std::regex math_pattern("[0-9+\\-\\*/ ]+");	


	if (std::regex_match(input, math_pattern) == false)
	{
		std::cerr << "Error: Invalid characters detected => " << input << std::endl;
		return (1);
	}

	return (0);
}

/*
	1. Convert digit [string to double]
	2. Add digit to stack
*/
void	RPN::pushDigitToStack(std::string line)
{
	double digit;

	digit = stod(line);
	// std::cout << "digit: " << digit << std::endl;

	this -> stack.push(digit);
}

/*
	1. Calculate top two numbers in stack together with operator (+, -, *, /) from line
	2. Pop top two numbers
	3. Replace (push) with Resulting number
*/
int		RPN::doALittleCalculation(std::string line)
{
	if (this->stack.size() < 2)
	{
		std::cerr << "Error: Stack needs at least two numbers before an operator." << std::endl;
		return (1);
	}

	double		num1;
	double		num2;
	double		result;

	num1 = stack.top();
	stack.pop();

	num2 = stack.top();
	stack.pop();

	if (line == "+")
	{
		result = num2 + num1;
	}
	if (line == "-")
	{
		result = num2 - num1;
	}
	if (line == "*")
	{
		result = num2 * num1;
	}
	if (line == "/")
	{
		result = num2 / num1;
	}

	stack.push(result);
	return (0);
}

/*
	If Input is
	i. digit
		-> Add to Stack
	ii. operator (+, -, *, /)
		-> Calculate with two top numbers in stack
*/
int		RPN::StackOrCalculate(std::string line)
{
	if (line.size() > 1)
	{
		std::cerr << "Error: Reformat => " << line <<  std::endl;
		return (1);
	}

	if (isdigit(line[0]))
	{
		pushDigitToStack(line);
	}
	else if (line == "+" || line[0] == '-' || line[0] == '*' || line[0] == '/')
	{
		if (doALittleCalculation(line) == 1)
			return (1);
	}
	else
	{
		std::cerr << "Error in Parsing - sumting wrong" << std::endl;
		return (1);
	}
	return (0);
}

/*
	Find each part of calculation delimited by space and make it into a string and send it to StackOrCalculate.
	f.ex. "2 3 +"
	line = "2";
*/
int		RPN::parseInput(std::string input)
{
	std::string		line;
	size_t			start;	
	size_t			end;

	start	= 0;
	end		= 0;

	while (42)
	{
		end = input.find(" ", start);
		line = input.substr(start, end - start);

		if (StackOrCalculate(line) == 1)
		{
			return (1);
		}

		if (end == std::string::npos)				//If We're at the end of string -> break
		{
			break ;
		}

		start = input.find_first_not_of(" ", end); // Skip trailing spaces 

		if (start == std::string::npos)				//If we skipped spaces and we're now at end -> break
		{
			break ;
		}

	}
	return (0);
}

/*
	1. Checks input for errors
	2. Parse input (goes to Main Program)
	3. Check if too many remaining numbers in stack
	4. Print Final Answer
*/
int	RPN::mainProgram(std::string input)
{
	if (checks(input) == 1)
	{
		return (1);
	}

	if (parseInput(input) == 1)
	{
		return (1);
	} 

	// Check that only One number (result) left in Stack [otherwise calculation didn't have enough operators]
	if (stack.size() > 1) 
	{
		std::cerr << "Error didn't provide enough operators. => " << stack.size() - 1 << " excess number(s) present" << std::endl;
		return (1);
	}

	//Print Final Answer
	std::cout << stack.top() <<  std::endl;

	return (0);
}
