#include <iostream>
#include <fstream>

int check_args(char **argv, std::string& filename, std::string& s1, std::string& s2) {
	if (argv && argv[1])
		filename.assign(argv[1]);
	else {
		std::cout << "Please provide a file!" << std::endl;
		return (1);
	}
	if (argv[2])
		s1 = argv[2];
	else {
		std::cout << "Please provide a string to replace!" << std::endl;
		return (1);
	} if (argv[3])
		s2 = argv[3];
	else {
		std::cout << "Please provide a replacement string!" << std::endl;
		return (1);
	}
	return (0);
}
int	main(int argc, char **argv)
{
	(void)argc;
	std::string filename;
	std::string	replaceFilename;
	std::string	s1;
	std::string s2;

	check_args(argv, filename, s1, s2);
	replaceFilename = filename;
	replaceFilename.append(".replace");

	std::ifstream file;
	file.open(filename.c_str());
	if (!file)
		std::cout << "Failed to open file" << filename << std::endl;
	std::ofstream replaceFile(replaceFilename.c_str());
	if (!replaceFile)
		std::cout << "Failed to create file" << replaceFilename << std::endl;
	std::string	buff;
	bool firstLine = true; // Track whether it's the first line
	while (std::getline(file, buff)) {  // Loop through all lines
		size_t start = buff.find(s1);
		while (start != std::string::npos) { // Replace all occurrences of s1 in the line
			buff.erase(start, s1.size());
			buff.insert(start, s2);
			start = buff.find(s1, start + s2.size());
		}
		if (!firstLine) { 
			replaceFile << '\n'; // Add newline before writing the line, except for the first line
		}
		replaceFile << buff;
		firstLine = false; // Set flag to false after the first line
	}
}
