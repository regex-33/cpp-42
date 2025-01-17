#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Zombie
{
    private:
        std::string name;
    public:
        ~Zombie(void);
        void announce();
        void setName(std::string name);
};


Zombie* zombieHorde( int N, std::string name);
Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif