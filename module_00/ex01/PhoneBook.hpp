#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"

class PhoneBook {
	private:
		int		_num_entries;
    public:
        Contact array[8];
        PhoneBook();
        ~PhoneBook();
        void    addContact(Contact *contact, int index);
        void    searchContact(Contact *array);

		// Setter
		void	setNumEntries(int num_entries) { _num_entries = num_entries; };
} ;

#endif