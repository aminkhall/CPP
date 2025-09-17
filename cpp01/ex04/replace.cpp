#include "Replace.hpp"

void ft_replace(std::ifstream& inFile, std::ofstream& outFile, const std::string& s1, const std::string& s2)
{
    if (s1.empty() || s1 == s2)
        return ;

    std::string line;

    while (std::getline(inFile, line))
    {
        size_t pos = 0;
        if (inFile.eof() == 0)
            line  += '\n';
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);            
            pos += s2.length();
        }
        outFile << line;
    }
}