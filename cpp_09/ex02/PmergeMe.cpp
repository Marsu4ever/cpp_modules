#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &copy) :
	vec(copy.vec),
	deq(copy.deq),
	vec_process_time(copy.vec_process_time),
	deque_process_time(copy.deque_process_time)
{

}

PmergeMe&	PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this -> vec					= copy.vec;
		this -> deq					= copy.deq;
		this -> vec_process_time 	= copy.vec_process_time;
		this -> deque_process_time	= copy.deque_process_time;
	}
	return (*this);
}

/*
	Checks for
	i. empty string
	ii. string size
	iii. format is (+)24 (+ is optional)
*/
int		PmergeMe::checkNumber(std::string &integer_string)
{
	if (integer_string == "")
	{
		std::cerr << "Error: Do not pass in empty strings." <<  std::endl;
		return (1);
	}

	if (integer_string.size() > 100)			//Protects regex from segfaulting with extremely long "00000" strings
	{
		std::cerr << "Error: What a looooooong number you got there. :)" <<  std::endl;
		return (1);	
	}
	
	std::regex positive_integer_pattern("[+]?[0-9]+");

	if (std::regex_match(integer_string, positive_integer_pattern) == false)
	{
		std::cerr << "Error: Argument should be a positive integer. ";
		std::cerr << "Only (+) and digits [0-9] are accepted. Your Input: " << integer_string <<  std::endl;
		return (1);
	}
	return (0);
}

int 	PmergeMe::addNumber(std::string integer_string)
{
	int	integer;

	if (checkNumber(integer_string) == 1)
	{
		return (1);
	}

	try
	{
		integer = stoi(integer_string);
	}
	catch(const std::out_of_range &e)			// Check if value greater than INTMAX
	{
		std::cerr << "Error: Pass in values that less than INTMAX (= 2147483647)." << std::endl;
		return (1);
	}
	
	this -> vec.push_back(integer);				//Pushes integer into VECTOR
	this -> deq.push_back(integer);				//Pushes integer into LIST

	return (0);
}

int		PmergeMe::duplicatesCheck()
{
	std::vector<size_t> vec_temp;
	
	vec_temp = this -> vec;

	std::sort(vec_temp.begin(), vec_temp.end());					//sorts vector
	if (std::adjacent_find(vec_temp.begin(), vec_temp.end()) != vec_temp.end())	//Checks if there are adjacent duplicates
	{
		std::cerr << "Error: No duplicates allowed." << std::endl;	
		return (1);
	}
	return (0);
}


std::vector<size_t>&	PmergeMe::getVector()
{
	return (this->vec);
}

void		PmergeMe::print_vector(std::vector<size_t>& vec, std::string name)
{
	std::cout << name;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

/*
	Find corresponding pair.
	a1 -> b1
	a2 -> b2
	[a values are from larger numbers]
*/
size_t	PmergeMe::find_pair(size_t a, std::vector<std::pair<size_t, size_t>>& pairs)
{
	for (std::pair<size_t, size_t> p : pairs)
	{
		if (a == p.first)
		{
			// std::cout <<  "Found pair value  (" << p.first  << ", " << p.second << ")" <<  std::endl;
			return (p.second);
		}
	}
	// std::cerr <<  "Error: Did not find pair value" << std::endl;
	return (0);
}

/*
	Find corresponding pair.
	a1 -> b1
	a2 -> b2
	[a values are from larger numbers]
*/
size_t	PmergeMe::find_pair_deq(size_t a, std::deque<std::pair<size_t, size_t>>& pairs)
{
	for (std::pair<size_t, size_t> p : pairs)
	{
		if (a == p.first)
		{
			// std::cout <<  "Found pair value  (" << p.first  << ", " << p.second << ")" <<  std::endl;
			return (p.second);
		}
	}
	// std::cerr <<  "Error: Did not find pair value" << std::endl;
	return (0);
}

/*
	Create jacobsthal sequence [as vector].
*/
std::vector<size_t>	PmergeMe::createJacobsthalSequence(size_t number_of_pairs)
{
	std::vector<size_t>	seq;			//sequence (1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461...)
	size_t				latestNumber;	// i.e.	latest sequence number

	seq.push_back(1);
	seq.push_back(3);

	latestNumber = 3;
	for(int i = 2; latestNumber < number_of_pairs; i++)
	{
		latestNumber = seq[i - 1] + 2 * seq[i - 2]; // n = (n-1) +  2 * (n - 2)
		seq.push_back(latestNumber);
	}
	return (seq);
}

void		PmergeMe::print_pairs(std::vector<std::pair<size_t, size_t>>& pairs, std::string name)
{
	std::cout << name;
	for (auto p: pairs)
	{
		std::cout << "(" <<  p.first << ", " << p.second << ") ";
	}
	std::cout << std::endl;
}

void		PmergeMe::print_pairs_deq(std::deque<std::pair<size_t, size_t>>& pairs, std::string name)
{
	std::cout << name;
	for (auto p: pairs)
	{
		std::cout << "(" <<  p.first << ", " << p.second << ") ";
	}
	std::cout << std::endl;
}

/*
	Binary Insertion using Jacobsthal Sequence
	1. Creates Jabobsthal Sequence
	2. Binary Insertion (into main)
		i. first smaller pair value (b1)
		ii. Rest of the b -values (b2, b3, b4...) using Jacobsthal Sequence 
*/
void	PmergeMe::insertionVecJacobStyle(std::vector<size_t>& main, std::vector<std::pair<size_t, size_t>>& pairs)
{
	std::vector<size_t> sequence;

	sequence = createJacobsthalSequence(pairs.size());

	std::vector<size_t> main_copy = main;		//Used for original index (i.e. main will be inserted, thus changes)

	// print_vector(main, "J Start: ");
	// print_pairs(pairs, "J Pairs: ");

	size_t number = find_pair(main[0], pairs);	//Find b1
	main.insert(main.begin(), number);			//Insert to front -> b1, a1, a2, a3...
	// print_vector(main, "J 1st insert: ");

	if (pairs.size() == 1)						//All values added from pairs.
	{
		return ;
	}

	for (size_t i = 1; i < sequence.size(); i++)	//Loop through Jacobsthal sequence
	{
		size_t	upper	= sequence[i];			// Current Jacobsthal number	(f.ex. 3)
		size_t	lower	= sequence[i-1];		// Previous Jacobsthal number	(f.ex. 1)


		for (size_t index = upper; index != lower; index--)	// Going reverse order (f.ex. 3, 2 OR 5, 4 OR 11, 10, 9, 8, 7, 6 OR etc)
		{
			if (index > pairs.size()) // Checks if index out of bounds
			{
				continue ;
			}

			// Find Corresponding b value
			size_t	number	= find_pair(main_copy[index - 1], pairs); 			// -1 for offset f.ex. main[1-1] -> a1 -> b1; main[2-1] -> a2 -> b2;
			
			// Find Position to insert
			auto position	= std::lower_bound(main.begin(), main.end(), number); 

			// Insert
			main.insert(position, number);
			// print_vector(main, "J Loop: ");	
		}
	}

	// print_vector(main, "J End: ");
	// std::cout << std::endl;
}

/*
	Ford-Johnson Algorithm - vector version
	(Note: Recursive function)
*/
void	PmergeMe::vecAlgorithm(std::vector<size_t>&	vec)
{
    if (vec.size() <= 1)	//Recursion end point
		return ;

	//1. Create Pairs (and sort pairs)
    std::vector<std::pair<size_t, size_t>> 	pairs;

    for (size_t i = 0; i + 1 < vec.size(); i += 2) 
	{
        if (vec[i] < vec[i + 1]) 				
			std::swap(vec[i], vec[i + 1]);		// Every pair (large number, small number)
        pairs.push_back({vec[i], vec[i + 1]});	
    }

	// 2. Save leftover (if odd amount of numbers)
	size_t	leftover;
	bool	isLeftover = false;

    if (vec.size() % 2 != 0)	// Odd amount
	{
		leftover = vec[vec.size() - 1];
		isLeftover = true;
	}


    // 3. Create vector with larger value from each pair
	std::vector<size_t> larger_numbers ;
    for (const auto& number : pairs)
	{
        larger_numbers.push_back(number.first);
    }

    // 4. Recursive function call
    vecAlgorithm(larger_numbers);


	//5. Binary Insertion
	insertionVecJacobStyle(larger_numbers, pairs);


	// 6. Binary insertion of (potential) Leftover
	if (isLeftover == true)
	{
		auto position = std::lower_bound(larger_numbers.begin(), larger_numbers.end(), leftover); 
		larger_numbers.insert(position, leftover);
	}

	// 7. Assign to vector
	vec = larger_numbers;
}

void	PmergeMe::vecSort()
{
	auto start_time = std::chrono::high_resolution_clock::now();

	
	vecAlgorithm(getVector());


	auto end_time = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed_time = end_time - start_time;

	this -> vec_process_time = elapsed_time.count();

}



void	PmergeMe::print_deque(std::deque<size_t>& deq, std::string name)
{
	std::cout << name;
	for (size_t i = 0; i < deq.size(); i++)
	{
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl;	
}

std::deque<size_t>&		PmergeMe::getDegue()
{
	return (this->deq);
}

std::deque<size_t>	PmergeMe::createJacobsthalSequenceDeq(size_t number_of_pairs)
{
	std::deque<size_t>	seq;			//jacobsthal sequence (0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461...)
	size_t				latestNumber;	// i.e.	latest sequence number

	seq.push_back(0);
	seq.push_back(1);

	latestNumber = 1;
	for(int i = 2; latestNumber < number_of_pairs; i++)
	{
		latestNumber = seq[i - 1] + 2 * seq[i - 2]; // n = (n-1) +  2 * (n - 2)
		seq.push_back(latestNumber);
	}
	return (seq);
}

/*
	Binary Insertion using Jacobsthal Sequence
	1. Creates Jabobsthal Sequence
	2. Binary Insertion (into main)
		i. first smaller pair value (b1)
		ii. Rest of the b -values (b2, b3, b4...) using Jacobsthal Sequence 
*/
void	PmergeMe::insertionDeqJacobStyle(std::deque<size_t>& main, std::deque<std::pair<size_t, size_t>>& pairs)
{
	std::vector<size_t> sequence;

	sequence = createJacobsthalSequence(pairs.size());

	std::deque<size_t> main_copy = main;		//Used for original index (i.e. main will be inserted, thus changes)

	// print_deque(main, "J Start: ");
	// print_pairs_deq(pairs, "J Pairs: ");

	size_t number = find_pair_deq(main[0], pairs);	//Find b1
	main.insert(main.begin(), number);				//Insert to front -> b1, a1, a2, a3...
	// print_deque(main, "J 1st insert: ");

	if (pairs.size() == 1)						//All values added from pairs.
	{
		return ;
	}

	for (size_t i = 1; i < sequence.size(); i++)	//Loop through Jacobsthal sequence
	{
		size_t	upper	= sequence[i];			// Current Jacobsthal number	(f.ex. 3)
		size_t	lower	= sequence[i-1];		// Previous Jacobsthal number	(f.ex. 1)


		for (size_t index = upper; index != lower; index--)	// Going reverse order (f.ex. 3, 2 OR 5, 4 OR 11, 10, 9, 8, 7, 6 OR etc)
		{
			if (index > pairs.size()) // Checks if index out of bounds
			{
				continue ;
			}

			// Find Corresponding b value
			size_t	number	= find_pair_deq(main_copy[index - 1], pairs); 			// -1 for offset f.ex. main[1-1] -> a1 -> b1; main[2-1] -> a2 -> b2;
			
			// Find Position to insert
			auto position	= std::lower_bound(main.begin(), main.end(), number); 

			// Insert
			main.insert(position, number);
			// print_deque(main, "J Loop: ");	
		}
	}

	// print_deque(main, "J End: ");
	// std::cout << std::endl;
}


/*
	Ford-Johnson Algorithm - deque version
	(Note: Recursive function)
*/
void	PmergeMe::dequeAlgorithm(std::deque<size_t>& dq)
{
    if (dq.size() <= 1)	//Recursion end point
		return ;

	//1. Create Pairs (and sort pairs)
    std::deque<std::pair<size_t, size_t>> 	pairs;

    for (size_t i = 0; i + 1 < dq.size(); i += 2) 
	{
        if (dq[i] < dq[i + 1]) 				
			std::swap(dq[i], dq[i + 1]);		// Every pair (large number, small number)
        pairs.push_back({dq[i], dq[i + 1]});	
    }

	// 2. Save leftover (if odd amount of numbers)
	size_t	leftover;
	bool	isLeftover = false;

    if (dq.size() % 2 != 0)	// Odd amount
	{
		leftover = dq[dq.size() - 1];
		isLeftover = true;
	}

    // 3. Create deque with larger value from each pair
	std::deque<size_t> larger_numbers;
    for (const auto& number : pairs)
	{
        larger_numbers.push_back(number.first);
    }

    // 4. Recursive function call
    dequeAlgorithm(larger_numbers);

	//5. Binary Insertion
	insertionDeqJacobStyle(larger_numbers, pairs);

	// 6. Binary insertion of (potential) Leftover
	if (isLeftover == true)
	{
		auto position = std::lower_bound(larger_numbers.begin(), larger_numbers.end(), leftover); 
		larger_numbers.insert(position, leftover);
	}

	// 7. Assign to Deque
	dq = larger_numbers;
}

void	PmergeMe::dequeSort()
{
	auto start_time = std::chrono::high_resolution_clock::now();

	
	dequeAlgorithm(getDegue());

	auto end_time = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed_time = end_time - start_time;

	this -> deque_process_time = elapsed_time.count();

}

void	PmergeMe::	print(char **argv)
{
	//1. Before
	std::cout << "Before:	" ;

	for (size_t i = 1; argv[i] != nullptr; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	//2. After
	std::cout << "After:	";

	for (size_t i = 0; i < this->vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	//3. Time to Process Vector
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector : " << this->vec_process_time << " seconds." << std::endl;

	// 4. Time to Process Deque
	std::cout << "Time to process a range of " << this->deq.size() << " elements with std::deque : " << this->deque_process_time << " seconds." << std::endl;

}
