#include "Harl.hpp"

int main (int argc, char **argv) {
	Harl harl;
	(void) argc;
	if (!argv[1])
	{
		std::cout << "Usage: ./harlFilter message_type [DEBUG] [INFO] [WARNING] [ERROR]" << std::endl;
		return 0;
	}
	std::string string(argv[1]);

	if (argc == 2)
		harl.complain(string);
	else
		std::cout << "Usage: ./harlFilter message_type [DEBUG] [INFO] [WARNING] [ERROR]" << std::endl;
	return 0;
}
