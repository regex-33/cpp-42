#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>


// #include "FragTrap.hpp"
// #include "ScavTrap.hpp"
// #include "DiamondTrap.hpp"



class ClapTrap
{
    protected:
            std::string name;
            int hitpoints;
            int energyPoints;
            int attackDamage;
            public:
                ClapTrap();
                ClapTrap(std::string name);
                ClapTrap(const ClapTrap &copy);

                ClapTrap &operator=(const ClapTrap &copy);
                ~ClapTrap();
                void attack(std::string const &target);
                void takeDamage(unsigned int amount);
                void beRepaired(unsigned int amount);

};






int check_energy(int energyPoints, std::string name, std::string target);
int check_hitpoints_repair(int hitpoints, std::string name, int mount);
int check_hitpoints(int hitpoints, std::string name, int flag, int mount);


#endif