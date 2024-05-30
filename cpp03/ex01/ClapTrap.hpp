#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

class ClapTrap
{
    private:
        std::string name;
        int hitpoints;
        int energyPoints;
        int attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        virtual void attack(std::string const &target);
        virtual void takeDamage(unsigned int amount);
        virtual void beRepaired(unsigned int amount);
        void set_hitpoints(int hitpoints)
        {
            this->hitpoints = hitpoints;
        }
        void set_energyPoints(int energyPoints)
        {
            this->energyPoints = energyPoints;
        }
        void set_attackDamage(int attackDamage)
        {
            this->attackDamage = attackDamage;
        }
        int get_hitpoints()
        {
            return this->hitpoints;
        }
        int get_energyPoints()
        {
            return this->energyPoints;
        }
        int get_attackDamage()
        {
            return this->attackDamage;
        }
        std::string get_name()
        {
            return this->name;
        }

};

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(std::string name);
        void attack(std::string const &target);
        void takeDamage(unsigned int amount); 
        void beRepaired(unsigned int amount);
        void guardGate();
};

int check_energy(int energyPoints);
int check_hitpoints_repair(int hitpoints, std::string name, int mount);
int check_hitpoints(int hitpoints, std::string name, int flag, int mount);


#endif