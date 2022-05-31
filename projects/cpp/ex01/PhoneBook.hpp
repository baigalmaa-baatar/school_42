#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook{
    public:
        PhoneBook();
        ~PhoneBook();
        void    search(void);

    private:
        Contact contacts[8];
};

#endif