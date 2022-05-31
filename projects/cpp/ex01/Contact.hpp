#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string.h>

class Contact{
    public:
        Contact();
        ~Contact();

        void    addContact();
        void    displayAll();
        void    displayOne(void);

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

};

#endif