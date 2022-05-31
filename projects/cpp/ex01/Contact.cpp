#include <iostream>
#include <string.h>
#include "Contact.hpp"

Contact::Contact(void){

}

Contact::~Contact(void){
    
}

void    Contact::addContact(void)
{
    // First name
    std::cout << "Please, enter first name: ";
    while (this->_firstName == "")
    {
        std::cout << "First name can't be empty: " << std::endl;
        std::cout << "Please, enter first name: " << std::endl;
        std::getline (std::cin, this->_firstName);
    }
    // Last name
    std::cout << "Please, enter last name: ";
    while (this->_lastName == "")
    {
        std::cout << "Last name can't be empty: " << std::endl;
        std::cout << "Please, enter last name: " << std::endl;
        std::getline (std::cin, this->_lastName);
    }
    // Nickname
    std::cout << "Please, enter nickname: ";
    while (this->_nickname == "")
    {
        std::cout << "Nickname can't be empty: " << std::endl;
        std::cout << "Please, enter nickname: " << std::endl;
        std::getline (std::cin, this->_nickname);
    }
    // Phone number
    std::cout << "Please, enter phone number: ";
    while (this->_phoneNumber == "")
    {
        std::cout << "Phone number can't be empty: " << std::endl;
        std::cout << "Please, enter phone number: " << std::endl;
        std::getline (std::cin, this->_phoneNumber);
    }
    // Darkest secret
    std::cout << "Please, enter darkest secret: ";
    while (this->_darkestSecret == "")
    {
        std::cout << "Darkest secret can't be empty: " << std::endl;
        std::cout << "Please, enter darkest secret: " << std::endl;
        std::getline (std::cin, this->_darkestSecret);
    }      
}

void    Contact::displayOne(void){

    std::cout << std::right << this->_firstName.substr(0, 10) << "|";
    std::cout << std::right << this->_lastName.substr(0, 10) << "|";
    std::cout << std::right << this->_phoneNumber.substr(0, 10) << std::endl;
}

void    Contact::displayAll(void)
{
    std::cout << "First name: " << this->_firstName << std::endl;
    std::cout << "Last name: "<< this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}
