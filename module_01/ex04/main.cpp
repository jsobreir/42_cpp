#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string filename;
	std::string	replace_filename;

	filename.assign(argv[1]);

	std::ifstream file;
	std::ofstream replace_file;

	file.open(filename);
	replace_filename.append(".replace");
	replace_file.open(replace_filename);
}