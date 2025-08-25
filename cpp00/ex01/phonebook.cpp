#include "phonebook.hpp"

PhoneBook::PhoneBook(): i(0){}

void PhoneBook::add_contact()
{
    if (i > 7)
        i = 0;
    contact[i].set_data(&i);
}

void PhoneBook::show_data()
{
    std::cout << "|" << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname" << "|" << std::endl;
    for (size_t j = 0; j < 8; j++)
    {
        if (!contact[j].is_set)
            return ;
        contact[j].get_data(j);
        std::cout << std::endl;
    }
}

void PhoneBook::search_contact(int index)
{
    if (index < 0 || index > 7) {
        std::cout << "Invalid index (must be 0 - 7)" << std::endl;
        return;
    }
    contact[index].get_index_data(index);
}
