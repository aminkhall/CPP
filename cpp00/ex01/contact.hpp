#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact{

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string dark_secret;

public:
    bool is_set;
    Contact();
    void set_data(int *index);
    void get_data(int index);
    void get_index_data(int index) const;
};

int is_valid(std::string str);
int is_digit(std::string str);

#endif