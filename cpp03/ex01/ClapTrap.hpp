#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

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
        // void set_hitpoints(int hitpoints)
        // {
        //     this->hitpoints = hitpoints;
        // }
        // void set_energyPoints(int energyPoints)
        // {
        //     this->energyPoints = energyPoints;
        // }
        // void set_attackDamage(int attackDamage)
        // {
        //     this->attackDamage = attackDamage;
        // }
        // int hitpoints
        // {
        //     return this->hitpoints;
        // }
        // int energyPoints
        // {
        //     return this->energyPoints;
        // }
        // int attackDamage
        // {
        //     return this->attackDamage;
        // }
        // std::string name
        // {
            // return this->name;
        // }

};

class ScavTrap : public ClapTrap
{
    private:
        int gate;
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(const ScavTrap &copy);
        // override the assignment operator
        ScavTrap &operator=(const ScavTrap &copy);
        ScavTrap(std::string name);

        void attack(std::string const &target);
        void guardGate();
};

int check_energy(int energyPoints);
int check_hitpoints_repair(int hitpoints, std::string name, int mount);
int check_hitpoints(int hitpoints, std::string name, int flag, int mount);


#endif