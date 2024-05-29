#include "sed.hpp"

/*
std::string::substr doesn't dynamically allocate memory; it creates a new std::string object that refers to a substring of the original string. Since substr doesn't allocate memory dynamically, you don't need to free anything explicitly, and hence there won't be memory leaks related to its usage.
*/
void ft_replace(std::string &line, std::ofstream &outFile, std::string s1, std::string s2)
{
    size_t pos = 0;
    size_t len = s1.length();
    std::string newLine;
    while (line[pos] != '\0')
    {
        pos = line.find(s1, pos);
        if (pos == std::string::npos)
            break;
        else
        {
            newLine = line.substr(0, pos);
            newLine += s2;
            newLine += line.substr(pos + len);
            line = newLine;
        }
        pos += len;
    }
    outFile << line << std::endl;
}

int main(int argc, char **argv)
{
    std::string line;
    if (argc != 4)
        return (std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl, 1);

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inFile(filename.c_str());
    if (!inFile)
        return (std::cerr << "Error: File not found or could not be opened!" << std::endl, 1);
    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile)
        return (std::cerr << "Error: Could not create output file!" << std::endl, 1);
    while (std::getline(inFile, line))
    {
        if (line.find(s1))
            ft_replace(line, outFile, s1, s2);
        else
            outFile << line << std::endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}