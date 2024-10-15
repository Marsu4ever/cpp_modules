
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>     //Here or in the main???

class Brain
{
	public:
		/* Orthodox canon */
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);


		std::string ideas[100];		//private/public?
						// -> called from constructors (private is ok)

		void print_ideas();

	private:

};

#endif