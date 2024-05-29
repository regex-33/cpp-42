#include "Harl.hpp"


/*
Comment ""fall through "": This comment is used to indicate to the compiler and human readers that the fall-through from one case to the next is intentional. This is a common practice in C++98 to avoid warnings about implicit fall-through.

Compatibility with C++98: By using this comment, you ensure that the code is compatible with the C++98 standard and avoid the need for C++11 or later features.*/

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Usage: ./harl [DEBUG/INFO/WARNING/ERROR]" << std::endl, 1);
    Harl k;
    switch (argv[1][0])
    {
        case 'D':
            k.complain("DEBUG");
            /* fall through */
        case 'I':
            k.complain("INFO");
            /* fall through */
        case 'W':
            k.complain("WARNING");
            /* fall through */
        case 'E':
            k.complain("ERROR");
            break;
        default:
            return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 1);
    }
    return 0;
}