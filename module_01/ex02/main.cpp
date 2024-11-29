#include <iostream>

int	main(void)
{
	std::string string_variable = "HI THIS IS BRAIN";
	std::string	*pointer_to_string = &string_variable;
	std::string	&ref_to_string = string_variable;

	std::cout << &string_variable << std::endl;
	std::cout << pointer_to_string << std::endl;
	std::cout << &ref_to_string << std::endl;

	std::cout << string_variable << std::endl;
	std::cout << *pointer_to_string << std::endl;
	std::cout << ref_to_string << std::endl;

}