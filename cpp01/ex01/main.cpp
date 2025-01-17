#include "Zombie.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
       return (std::cerr << "Error: Usage: ./zombieHorde [number of zombies] [name]" << std::endl, 1);
    if (argv[2] == 0 || argv[2][0] == '\0')
        return (std::cerr << "Error: Name is either null or an empty string." << std::endl, 1);
    int N = std::atoi(argv[1]);
    if (N <= 0)
        return (std::cerr << "Error: Number of zombies must be a positive integer" << std::endl, 1);
    Zombie* horde = zombieHorde(N, argv[2]);
    if (!horde)
        return (std::cerr << "Error: Failed to create zombie horde" << std::endl, 1);

    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete [] horde;
    return 0;
}

/*
When user requested a memory from heap using malloc() function / new()
operator

Operating system takes the call and allocated more than requested memory.
That extra memory acts as a header. Which maintains all the meta
information about allocated chuck memory

For Example:

Char *ptr=Malloc(100 bytes)

Now OS allocates 100 bytes+ Header

Header is like

Struct header {

int start_address,

int Numberof bytes,

}

When user call free( ptr) ,

Internally free function see the header and know the number of bytes needs
to release.
*/