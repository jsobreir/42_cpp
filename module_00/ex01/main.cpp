#include "phonebook.h"

int main(int argc, char **argv)
{
    int index = 0;
    Contact     contacts[8];
    PhoneBook   phone_book;
    std::string	input;
	(void)argc;
	(void)argv;

    while (1)
    {
        std::cin >> input;
        if (!input.compare("ADD"))
		{
            phone_book.addContact(contacts, index);
			index++;
			phone_book.setNumEntries(index % 8);
		}
        else if (!input.compare("SEARCH"))
            phone_book.searchContact(contacts);
        else if (!input.compare("EXIT"))
            break ;
    }
}