#pragma once

#include <iostream>
#include <stack>
#include <regex>
#include <cctype>		//std::isdigit()

class RPN
{
	private:
		std::stack<double> stack;
	
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		const RPN& operator=(const RPN& other);

		int		mainProgram(std::string input);
		int		checks(std::string input);
		int		StackOrCalculate(std::string line);
		void	pushDigitToStack(std::string line);
		int		parseInput(std::string input);
		int		doALittleCalculation(std::string line);
};
