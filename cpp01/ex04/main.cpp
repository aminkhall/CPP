#include <iostream>
#include <fstream>

void ft_replace(std::ifstream& file, const std::string& s1, const std::string& s2)
{
    if (s1.empty() || s1 == s2)
        return ;
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);            
            pos += s2.length();
        }
        // outFile << line << std::endl;
    }
    
}

int main(int ac, char **av){
    if (ac != 4){
        std::cout << "Error" << std::endl;
        return (1);
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::cout << filename << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    std::ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()){
        std::cout << "Failed to open file" << std::endl;
        return (1);
    }
    ft_replace(inFile, s1, s2);
    inFile.close();
    return (0);
}