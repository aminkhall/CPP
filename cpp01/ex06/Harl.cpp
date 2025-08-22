#include "Harl.hpp"

void Harl::debug(){
    std::cout << 
                "[DEBUG]\n"
                "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
                "ketchup burger. I really do!" 
                << std::endl;
}
void Harl::info(){
    std::cout <<
                 "[INFO]\n"
                "I cannot believe adding extra bacon costs more money. You didn’t put"
                "enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
                << std::endl;
}
void Harl::warning(){
    std::cout << 
                "[WARNING]\n"
                "I think I deserve to have some extra bacon for free. I’ve been coming for"
                "years, whereas you started working here just last month." 
                << std::endl;
}
void Harl::error(){
    std::cout << 
                "[ERROR]\n"
                "This is unacceptable! I want to speak to the manager now." 
                << std::endl;
}

void Harl::complain(std::string level){
    void (Harl::*funcArray[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error }; 

    std::string funLevel[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    size_t i;
    for (i = 0; i < 4; i++)
    {
        if (level == funLevel[i])
            break;
    }
    switch (i)
    {
        case 0:
            (this->*funcArray[i])();
            break;
        case 1:
            (this->*funcArray[i])();
            break;
        case 2:
            (this->*funcArray[i])();
            break;
        case 3:
            (this->*funcArray[i])();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
}