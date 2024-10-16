
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

		/* Methods... */
		void set_idea(const std::string &idea);
		void print_ideas();

	private:
		std::string ideas[100];

};

#endif