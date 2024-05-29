#include <iostream>
#include <string>
#include <cstdlib>


int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string* stringPTR = &name;
    std::string& stringREF= name;


    std::cout << "Address in memory of the string: " << &name << std::endl;
    std::cout << "Address in memory of the string: " << &*stringPTR << std::endl;
    std::cout << "Address in memory of the string: " << &stringREF << std::endl;

    std::cout << "String: " << name << std::endl;
    std::cout << "PTR value: " << *stringPTR << std::endl;
    std::cout << "REF value: " << stringREF << std::endl;

    return 0;
}