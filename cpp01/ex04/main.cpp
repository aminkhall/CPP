#include "Replace.hpp"

int main(int ac, char **av){
    if (ac != 4){
        std::cout << "Error" << std::endl;
        return (1);
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    
    std::ifstream inFile(filename);
    if (!inFile){
        std::cout << "Failed to open file" << std::endl;
        return (1);
    }
    std::ofstream outFile(filename + ".replace");
    if (!outFile){
        std::cout << "Failed to open/create file" << std::endl;
        return (1);
    }
    ft_replace(inFile, outFile, s1, s2);
    return (0);
}