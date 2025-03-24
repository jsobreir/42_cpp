#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 0;
	}
	ScalarConverter convert(argv[1]);
	return 1;
}
