
#include "StrReplace.hpp"

StrReplace::StrReplace()
{

}

StrReplace::~StrReplace()
{
	
}

std::string&		StrReplace::search_and_replace_in_line(std::string&	line, std::string& s1, std::string& s2) const
{
	size_t			s1_start;
	
	s1_start = 0;
	while (1)
	{
		s1_start = line.find(s1, s1_start);
		if (s1_start == std::string::npos)
		{
			break;
		}
		line = line.substr(0, s1_start) + s2 + line.substr(s1_start +  s1.length());
		s1_start += s2.length();
	}
	return (line);
}

void	StrReplace::replace_function(std::ifstream& in, std::ofstream& out, std::string& s1, std::string& s2) const
{
	std::string	line;

	while(getline(in, line))
	{
		out << search_and_replace_in_line(line, s1, s2);
		if (in.eof() == false)
		{
			out << '\n';
		}
	}
}

bool	StrReplace::check_if_files_opened(std::ifstream& in, std::ofstream& out) const
{
	if (in.fail() == true)
	{
		std::cerr << "Error: Failed to open --- std::ifstream in(file)." <<std::endl;
		return (false);
	}
	if (!out)
	{
		std::cerr << "Error: Failed to open --- std::ofstream out(of_name)." <<std::endl;
		return (false);
	}
	return (true);
}

std::string		StrReplace::make_outfile_name(std::string file) const
{
	std::string 	outfile_name;
	
	outfile_name = file;
	outfile_name += ".replace";

	return (outfile_name);
}

int		StrReplace::replace_file_strings(std::string file, std::string& s1, std::string& s2) const
{
	std::string 	of_name;

	of_name = make_outfile_name(file);
	
	/*Open file streams*/
	std::ifstream	in(file);
	std::ofstream	out(of_name);

	if (check_if_files_opened(in, out) == false)
	{
		return (1);
	}
	replace_function(in, out, s1, s2);

	in.close();
	out.close();
	return (0);
}

bool	StrReplace::error_in_argument_syntax(std::string file, std::string s1) const
{
	if (file.empty() == true)
	{
		std::cerr << "Error: File is an empty string - tsot tsot." << std::endl;
		return (true);
	}
	if (s1.empty() == true)
	{
		std::cerr << "Error: s1 string is empty." << std::endl;
		return (true);
	}
	return (false);
}
