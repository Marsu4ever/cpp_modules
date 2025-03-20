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

std::vector<size_t>	PmergeMe::createjacobsthalSequence(size_t pendingSize)
{
	std::vector<size_t>	seq;			//jacobsthal sequence (0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461...)
	size_t				latestNumber;	// i.e.	latest sequence number

	seq.push_back(0);
	seq.push_back(1);

	latestNumber = 1;
	for(int i = 2; latestNumber < pendingSize; i++)
	{
		latestNumber = seq[i - 1] + 2 * seq[i - 2]; // n = (n-1) +  2 * (n - 2)
		seq.push_back(latestNumber);
	}
	return (seq);
}

void	PmergeMe::insertionVecJacobStyle(std::vector<size_t>& main, std::vector<size_t>& pending)
{
	std::vector<size_t> sequence;
	std::vector<size_t>	index_of_added_number;

	sequence = createjacobsthalSequence(pending.size());	//Create JacobsthanSequence

	for (size_t i = 0; i < sequence.size() && i < pending.size(); i++)	//Insert numbers at Jacobsthal sequence index
	{
		if (sequence[i] >= pending.size())
			break ;
		if (i == 2)														//Skip duplicate "1" // 0, 1, 1, 3....
			continue ;
		size_t	number	= pending[sequence[i]];
		auto position	= std::lower_bound(main.begin(), main.end(), number);
		main.insert(position, number);
		index_of_added_number.push_back(sequence[i]);
	}
	for (size_t i = 0; i < pending.size(); i++)							//Insert rest of numbers
	{
		if (std::find(index_of_added_number.begin(), index_of_added_number.end(), i) != index_of_added_number.end())	//Check used Jacobsthal index
			continue ;
		size_t	number = pending[i];
		auto position = std::lower_bound(main.begin(), main.end(), number); 
		main.insert(position, number);
	}
}

void	PmergeMe::vecAlgorithm(std::vector<size_t>&	vec)
{
	if (vec.size() == 1)
		return ;

	std::vector<size_t>	main;
	std::vector<size_t>	pending;

	size_t vecSize = vec.size();

	for (size_t i = 0; i + 1 < vecSize; i += 2)
	{
		if (vec[i] > vec[i+1])
		{
			main.	push_back(vec[i]);
			pending.push_back(vec[i+1]);
		}
		else
		{
			main.	push_back(vec[i+1]);
			pending.push_back(vec[i]);			
		}
	}
	if (vecSize % 2 != 0)
	{
		main.push_back(vec[vecSize - 1]);
	}

	vecAlgorithm(main);

	insertionVecJacobStyle(main, pending);

	vec = main;
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

std::deque<size_t>	PmergeMe::createjacobsthalSequenceDeq(size_t pendingSize)
{
	std::deque<size_t>	seq;			//jacobsthal sequence (0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461...)
	size_t				latestNumber;	// i.e.	latest sequence number

	seq.push_back(0);
	seq.push_back(1);

	latestNumber = 1;
	for(int i = 2; latestNumber < pendingSize; i++)
	{
		latestNumber = seq[i - 1] + 2 * seq[i - 2]; // n = (n-1) +  2 * (n - 2)
		seq.push_back(latestNumber);
	}
	return (seq);
}

void	PmergeMe::insertionDeqJacobStyle(std::deque<size_t>& main, std::deque<size_t>& pending)
{
	std::deque<size_t>	sequence;
	std::deque<size_t>	index_of_added_number;

	sequence = createjacobsthalSequenceDeq(pending.size());

	for (size_t i = 0; i < sequence.size() && i < pending.size(); i++)	//Insert numbers at Jacobsthal sequence index
	{
		if (sequence[i] >= pending.size())
			break ;
		if (i == 2)														//Skip duplicate "1" // 0, 1, 1, 3....
			continue ;
		size_t	number	= pending[sequence[i]];
		auto position	= std::lower_bound(main.begin(), main.end(), number);
		main.insert(position, number);
		index_of_added_number.push_back(sequence[i]);
	}
	for (size_t i = 0; i < pending.size(); i++)							//Insert rest of numbers
	{
		if (std::find(index_of_added_number.begin(), index_of_added_number.end(), i) != index_of_added_number.end())
			continue ;
		size_t	number = pending[i];
		auto position = std::lower_bound(main.begin(), main.end(), number); 
		main.insert(position, number);
	}
}

void	PmergeMe::dequeAlgorithm(std::deque<size_t>& dq)
{

	if (dq.size() == 1)
		return ;

	std::deque<size_t>	main;
	std::deque<size_t>	pending;

	size_t dqSize = dq.size();

	for (size_t i = 0; i + 1 < dqSize; i += 2)
	{
		if (dq[i] > dq[i+1])
		{
			main.	push_back(dq[i]);
			pending.push_back(dq[i+1]);
		}
		else
		{
			main.	push_back(dq[i+1]);
			pending.push_back(dq[i]);			
		}
	}
	if (dqSize % 2 != 0)
	{
		main.push_back(dq[dqSize - 1]);
	}

	dequeAlgorithm(main);

	insertionDeqJacobStyle(main, pending);

	dq = main;
}

void	PmergeMe::dequeSort()
{
	auto start_time = std::chrono::high_resolution_clock::now();

	
	dequeAlgorithm(getDegue());

	auto end_time = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed_time = end_time - start_time;

	this -> deque_process_time = elapsed_time.count();

}

void	PmergeMe::print(char **argv)
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

		std::cout << "After:	";

	for (size_t i = 0; i < this->deq.size(); i++)
	{
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl;

	//3. Time to Process Vector
	std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector : " << this->vec_process_time << " seconds." << std::endl;

	//4. Time to Process Deque
	std::cout << "Time to process a range of " << this->deq.size() << " elements with std::deque : " << this->deque_process_time << " seconds." << std::endl;
}
