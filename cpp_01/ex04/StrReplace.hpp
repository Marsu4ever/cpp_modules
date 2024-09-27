
#ifndef STRREPLACE_HPP
#define STRREPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class StrReplace
{
	public:
		StrReplace();
		~StrReplace();
		
		bool	error_in_argument_syntax(std::string file, std::string s1) const;
		int		replace_file_strings(std::string file, std::string& s1, std::string& s2) const;

	private:
		bool			check_if_files_opened(std::ifstream& in_file, std::ofstream& out_file) const;
		std::string		make_outfile_name(std::string file) const;
		void			replace_function(std::ifstream& in, std::ofstream& out, std::string& s1, std::string& s2) const;
		std::string&	search_and_replace_in_line(std::string&	line, std::string& s1, std::string& s2) const;

};

#endif