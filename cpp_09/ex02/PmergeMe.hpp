
#pragma once

#include <iostream>
#include <regex>
#include <vector>
#include <deque>
#include <chrono> 		//std::chrono::high_resolution_clock::now()
#include <algorithm> 	//std::lower_bound

class PmergeMe
{
	private:

		std::vector	<size_t>	vec;
		std::deque	<size_t>	deq;

		double				vec_process_time;	//in seconds;
		double				deque_process_time;	//in seconds;

	public:

		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &copy);

		//Init and Check functions
		int		addNumber(std::string integer);
		int		checkNumber(std::string &integer_string);

		//Vector methods
		void					vecSort();
		std::vector<size_t>&	getVector();
		void					vecAlgorithm(std::vector<size_t>&	main);
		void					insertionVecJacobStyle(std::vector<size_t>& main, std::vector<size_t>& pending);
		std::vector<size_t>		createjacobsthalSequence(size_t pendingSize);

		//Deque methods
		void					dequeSort();
		std::deque<size_t>&		getDegue();
		void					dequeAlgorithm(std::deque<size_t>& deq);	
		void					insertionDeqJacobStyle(std::deque<size_t>& main, std::deque<size_t>& pending);

		std::deque<size_t>		createjacobsthalSequenceDeq(size_t pendingSize);
		
		//Print final result
		void		print(char **argv);

		//Debug
		void		print_vector(std::vector<size_t>& vec, std::string name);
		void		print_deque(std::deque<size_t>& deq, std::string name);

};
