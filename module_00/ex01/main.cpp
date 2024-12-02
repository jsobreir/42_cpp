#include "phonebook.h"

int main(int argc, char **argv)
{
    int index = -1;
    Contact     contacts[8];
    PhoneBook   phone_book;
    std::string	input;
	(void)argc;
	(void)argv;

    while (!std::cin.eof())
    {
        std::cin >> input;
        if (!input.compare("ADD"))
		{
            phone_book.addContact(contacts, index);
			if (phone_book.getNumEntries() < 8)
				phone_book.setNumEntries(phone_book.getNumEntries() + 1);

		}
        else if (!input.compare("SEARCH"))
            phone_book.searchContact(contacts, phone_book.getNumEntries());
        else if (!input.compare("EXIT"))
            break ;
    }
}