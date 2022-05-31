#include <iostream>
#include <string.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    // std::cout << "Phonebook has created." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    // std::cout << "Phonebook has deleted." << std::endl;
}

void    PhoneBook::search(void)
{
    int i = 0;
    int index = 0;
    
    while (i < 8)
    {
        std::cout << "Index | First name | Last name | Nickname" << std::endl;
        std::cout <<  i << "|";
        contacts[i].displayOne();
        i++;
    }
    
    while (1)
    {
        std::cout << "\001\033[32m\002Enter the search index: \001\033[0m\002 " << std::endl;
        std::cin >> index;
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "\001\033[32m\002Enter the index between 0 to 7.\001\033[0m\002 " << std::endl;
        }
        else if (index >= 0 && index < 8)
        {
            // if (this->contacts[index]. //_firstName.length() != 0)
            // {
                contacts[index].displayAll();
                break;
            // }
            // else
                // std::cout << "\001\033[32m\002Enter existing contact index number.\001\033[0m\002 " << std::endl;
        }
        else
            std::cout << "\001\033[32m\002Enter the index between 0 to 7.\001\033[0m\002 " << std::endl;
    }
}
