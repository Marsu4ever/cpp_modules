
#include "StrReplace.hpp"

/*
	Tests

	0. [no args to program]
	1. "" "" ""
	2. in.txt "" ""
	3. in.txt "a" ""
	4. in.txt "a" "b"
	5. in.txt "a" "bb"
	6. in.txt "a" "aa"
	7. no_exist "a" "b"
*/


int main(int argc, char **argv)
{
	StrReplace	obj;
	std::string	file;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
	{
		std::cerr << "Error: Pass in exactly 3 arguments: Filename, s1(to_replace), s2(replace_with)" << std::endl;
		return (1);
	}

	file 	= argv[1];
	s1 		= argv[2];
	s2		= argv[3];

	if (obj.error_in_argument_syntax(file, s1) == true)
	{
		return (1);
	}
	if (obj.replace_file_strings(file, s1, s2) == 1)
	{
		return (1);
	}
	return (0);
}
