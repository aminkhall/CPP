#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
    while (std::getline(std::cin, command))
    {
        if (command == "EXIT")
            return (0);
        else if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
        {
            std::string a_index;
            phonebook.show_data();
            std::cout << "Enter an index: ";
            std::getline(std::cin, a_index);
            if (is_digit(a_index))
            {
                int index = stoi(a_index);
                if (index > 7 || index < 0)
                    std::cout << "Invalid index ((Enter a digit) between 0 and 7)" << std::endl;
                else
                    phonebook.search_contact(index);
            }
        }
        else
            std::cout << "Enter a valid command" << std::endl;
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
    }
    return (0);
}