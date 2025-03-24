
#pragma once

#include <iostream>
#include <regex>
#include <vector>
#include <deque>
#include <chrono> 		//std::chrono::high_resolution_clock::now()
#include <algorithm> 	//std::lower_bound, std::swap, std:sort

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
		int		duplicatesCheck();


		//Vector methods
		void					vecSort();
		std::vector<size_t>&	getVector();
		void					vecAlgorithm(std::vector<size_t>&	main);
		void					insertionVecJacobStyle(std::vector<size_t>& larger_numbers, std::vector<std::pair<size_t, size_t>>& 	pairs);
		size_t					find_pair(size_t a, std::vector<std::pair<size_t, size_t>>& pairs);
		std::vector<size_t>		createJacobsthalSequence(size_t number_of_pairs);


		//Deque methods
		void					dequeSort();
		std::deque<size_t>&		getDegue();
		void					dequeAlgorithm(std::deque<size_t>& deq);	
		void					insertionDeqJacobStyle(std::deque<size_t>& main, std::deque<std::pair<size_t, size_t>>& pairs);
		size_t					find_pair_deq(size_t a, std::deque<std::pair<size_t, size_t>>& pairs);
		std::deque<size_t>		createJacobsthalSequenceDeq(size_t number_of_pairs);
		
		//Print final result
		void		print(char **argv);

		//Debug
		void		print_vector(std::vector<size_t>& vec, std::string name);
		void		print_pairs(std::vector<std::pair<size_t, size_t>>& pairs, std::string name);

		void		print_deque(std::deque<size_t>& deq, std::string name);
		void		print_pairs_deq(std::deque<std::pair<size_t, size_t>>& pairs, std::string name);
};
