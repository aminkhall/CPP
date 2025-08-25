#include "contact.hpp"




Contact::Contact() : is_set(false) {}
void Contact::set_data(int *index)
{
    std::string fname;
    std::string lname;
    std::string nname;
    std::string pnum;
    std::string dscrt;
    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, fname)) exit(1);
    if (!is_valid(fname)) return;
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, lname)) exit(1);
    if (!is_valid(lname)) return;
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nname)) exit(1);
    if (!is_valid(nname)) return;
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, pnum)) exit(1);
    if (!is_valid(pnum)) return;
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, dscrt)) exit(1);
    if (!is_valid(dscrt)) return;
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
        std::cout << "First name: " << first_name << std::endl;
        std::cout << "Last name: " << last_name << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone number: " << phone_number << std::endl;
        std::cout << "Darkest secret: " << dark_secret << std::endl;
    }
    else
        std::cout << "Not found" << std::endl;
}
