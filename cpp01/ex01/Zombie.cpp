#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::~Zombie(){
    std::cout << name << ": Deleted." << std::endl;
}

void Zombie::setName(std::string str){
    name = str;
}

void Zombie::announce( void ){
    std::cout << name << ": Moar brainz!" << std::endl;
}