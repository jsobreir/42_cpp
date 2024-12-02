#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"

class PhoneBook {
	private:
		int		_numEntries;
    public:
        Contact array[8];
        PhoneBook();
        ~PhoneBook();
        void    addContact(Contact *contact, int &index);
        void    searchContact(Contact *array, int _numEntries);

		// Setter
		void	setNumEntries(int num_entries) { _numEntries = num_entries; };
		int getNumEntries(void) const { return _numEntries; }
} ;

#endif