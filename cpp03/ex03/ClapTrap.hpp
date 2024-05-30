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

class FragTrap : public ClapTrap
{
    private:
        int gate;
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);
        ~FragTrap();
        void highFivesGuys(void);
};

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator=(const DiamondTrap &copy);
        ~DiamondTrap();
        void whoAmI();
};

int check_energy(int energyPoints, std::string name, std::string target);
int check_hitpoints_repair(int hitpoints, std::string name, int mount);
int check_hitpoints(int hitpoints, std::string name, int flag, int mount);


#endif