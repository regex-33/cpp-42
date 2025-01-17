#include "Harl.hpp"


/*
Comment ""fall through "": This comment is used to indicate to the compiler and human readers that the fall-through from one case to the next is intentional. This is a common practice in C++98 to avoid warnings about implicit fall-hrough.
*/

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Usage: ./harl [DEBUG/INFO/WARNING/ERROR]" << std::endl, 1);
    Harl k;
    std::string input = std::string(argv[1]);
    switch (k.getIndex(input))
    {
        case 0:
            k.complain("DEBUG");
            /* fall through */
        case 1:
            k.complain("INFO");
            /* fall through */
        case 2:
            k.complain("WARNING");
            /* fall through */
        case 3:
            k.complain("ERROR");
            break;
        default:
            return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 1);
    }
    return 0;
}


