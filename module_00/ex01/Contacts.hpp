#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <cstring>
# include <sstream>
# include <string>

class Contact {
    private:
        int				index;
        std::string  	first_name;
        std::string  	last_name;
        std::string  	nickname;
		std::string		phone_number;
		std::string		darkest_secret;
    public:
        Contact() {};
        ~Contact() {};
        // Setters
        void setFirstName(const std::string &name) { first_name = name; }
        void setLastName(const std::string &name) { last_name = name; }
        void setNickname(const std::string &name) { nickname = name; }
        void setPhoneNumber(const std::string &name) { phone_number = name; }
        void setDarkestSecret(const std::string &name) { darkest_secret = name; }
        void setIndex(int idx) { index = idx; }
        // Getters
        std::string getFirstName() const { return first_name; }
        std::string getLastName() const { return last_name; }
        std::string getNickname() const { return nickname; }
        int getIndex() { return index; }
} ;

#endif