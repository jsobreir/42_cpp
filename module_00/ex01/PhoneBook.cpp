#include "phonebook.h"

PhoneBook::PhoneBook() {
	_numEntries = 0;
}

PhoneBook::~PhoneBook() {
	return ;
}
std::string	getUserInput(std::string	input) {
	while (true) {
	    std::getline(std::cin, input);
	    input.erase(0, input.find_first_not_of(" \t\n\r"));
	    input.erase(input.find_last_not_of(" \t\n\r") + 1);
	    if (!input.empty())
	        break;
		return input;
	}
}

void    PhoneBook::addContact(Contact *contact, int &index) {
    std::string      f_name, l_name, n_name, p_number, d_secret;

    std::cout << "Creating a new contact." << std::endl;
    std::cout << "First Name:" << std::endl;
	index = (index + 1) % 8;
	contact[index].setIndex(index);
    f_name = getUserInput(f_name);
    contact[index].setFirstName(f_name);
    std::cout << "Last Name:" << std::endl;
    l_name = getUserInput(l_name);
    contact[index].setLastName(l_name);
    std::cout << "Nickname:" << std::endl;
    n_name = getUserInput(n_name);
    contact[index].setNickname(n_name);
    std::cout << "Phone Number:" << std::endl;
    p_number = getUserInput(p_number);
    contact[index].setPhoneNumber(p_number);
    std::cout << "Darkest Secret:" << std::endl;
    d_secret = getUserInput(d_secret);
    contact[index].setDarkestSecret(d_secret);
    return ;
}

void	print_search(std::string print) {
	int	whitespaces = print.size();

	if (whitespaces >= 10)
	{
		std::string	sub_print = print.substr(0, 9);
		std::cout << sub_print;
		std::cout << '.';
	}
	else
	{
		whitespaces = 10 - whitespaces;
		while (whitespaces--)
			std::cout << " ";
		std::cout << print;
	}
	std::cout << '|';
	return ;
}

static void	print_all(Contact *array, int _numEntries) {
	std::ostringstream str1;

	for (int idx = 0; idx < _numEntries; idx++)
	{
		std::ostringstream str1;
		str1 << array[idx].getIndex();
		std::string index = str1.str();
		print_search(index);
		print_search(array[idx].getFirstName());
		print_search(array[idx].getLastName());
		print_search(array[idx].getNickname());
		std::cout << std::endl;
	}
}

void    PhoneBook::searchContact(Contact *array, int _numEntries) {
	int	index = -1;
	std::ostringstream str1;
	bool print = true;

	print_all(array, _numEntries);
	std::cout << "Enter the index:";
	while (index < 0)
	{
		std::cin >> index;
		if (std::cin.fail()) {
        	std::cout << "Invalid input. Please enter an integer." << std::endl;
			std::cin.clear();                 // Clear the error state
			std::cin.ignore(1000, '\n');      // Discard invalid input from the buffer
			print = false;
			break ;
		}
	}
	if (index < _numEntries && print == true)
	{
		str1 << array[index].getIndex();
		std::string idx = str1.str();
		print_search(idx);
		print_search(array[index].getFirstName());
		print_search(array[index].getLastName());
		print_search(array[index].getNickname());
		std::cout << std::endl;
	}
	else if (print == true)
		std::cout << "No contact with such index." << std::endl;
}
