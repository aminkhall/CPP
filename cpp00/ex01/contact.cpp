#include "contact.hpp"

Contact::Contact(): is_set(false){}
void Contact::set_data(int *index)
{
    std::string fname;
    std::string lname;
    std::string nname;
    std::string pnum;
    std::string dscrt;
    std::cout << "Enter first name: ";
    std::getline(std::cin, fname);
    if (!is_valid(fname)) return ;
    std::cout << "Enter last name: ";
    std::getline(std::cin, lname);
    if (!is_valid(lname)) return ;
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nname);
    if (!is_valid(nname)) return ;
    std::cout << "Enter phone number: ";
    std::getline(std::cin, pnum);
    if (!is_valid(pnum)) return ;
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, dscrt);
    if (!is_valid(dscrt)) return ;
    first_name = fname;
    last_name = lname;
    nickname = nname;
    phone_number = pnum;
    dark_secret = dscrt;
    is_set = true;
    ++(*index);
}

void Contact::get_data(int index)
{
    std::cout << "|" << std::setw(10) << std::right << index;
    if (first_name.length() > 10)
        std::cout << "|" << first_name.substr(0, 9) << '.';
    else
        std::cout << "|" << std::setw(10) << std::right << first_name;
    if (last_name.length() > 10)
        std::cout << "|" << last_name.substr(0, 9) << '.';
    else
        std::cout << "|" << std::setw(10) << std::right << last_name;
    if (nickname.length() > 10)
        std::cout << "|" << nickname.substr(0, 9) << '.' << "|";
    else
        std::cout << "|" << std::setw(10) << std::right << nickname << "|";
}

void Contact::get_index_data(int index) const
{
    if (index < 8 && index >= 0 && is_set)
    {
        std::cout << first_name << std::endl;
        std::cout << last_name << std::endl;
        std::cout << nickname << std::endl;
        std::cout << phone_number << std::endl;
        std::cout << dark_secret << std::endl;
    }
    else
        std::cout << "Don't found" << std::endl;
}
