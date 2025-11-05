#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
// #include <cctype>
#include "contact.hpp"

class PhoneBook{
private:
    Contact contact[8];
public:
    int i;
    PhoneBook();
    void add_contact();
    void show_data();
    void search_contact(int index);
};

#endif