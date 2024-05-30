#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    gate = copy.gate;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    ClapTrap::operator=(copy);
    gate = copy.gate;
    return (*this);
}


int check_hitpoints2(int hitpoints, std::string name, int check, unsigned int amount)
{
    if (hitpoints == 0)
    {
        if (check == 0)
            std::cout << "\033[31mScavTrap " << name << " is already dead.\033[0m" << std::endl;
        return (0);
    }
    if (amount == 0)
    {
        if (check == 0)
            std::cout << "\033[31mScavTrap " << name << " can't be healed, because he is already at full health.\033[0m" << std::endl;
        return (0);
    }
    return (1);
}

int check_hitpoints_repair2(int hitpoints, std::string name, unsigned int amount)
{
    if (hitpoints == 0)
    {
        std::cout << "\033[31mScavTrap " << name << " is already dead.\033[0m" << std::endl;
        return (0);
    }
    if (amount == 0)
    {
        std::cout << "\033[31mScavTrap " << name << " can't be healed, because he is already at full health.\033[0m" << std::endl;
        return (0);
    }
    if (hitpoints + amount > 100 || (hitpoints == 100 && amount > 0))
    {
        std::cout << "\033[33mScavTrap " << name << " can't be repaired to have more than 100 hit points.\033[0m" << std::endl;
        return (0);
    }
    return (1);
}

// int check_energy2(int energy)
// {
//     if (energy == 0)
//     {
//         std::cout << "\033[31mScavTrap doesn't have enough energy points to perform this action.\033[0m" << std::endl;
//         return (0);
//     }
//     return (1);
// }

ScavTrap::ScavTrap() : ClapTrap(), gate(0)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    hitpoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gate(0)
{
    name = name + "_clap_name";
    std::cout << "ScavTrap constructor from name " << name << " called" << std::endl;
    hitpoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructor called" << std::endl;   // Remove the redeclaration of ClapTrap::~ClapTrap() here
}

void ScavTrap::attack(std::string const &target)
{
    if (check_energy(energyPoints, name, target) == 0)
        return;
    if (hitpoints == 0)
        return (std::cout << "\033[31mScavTrap " << target << " is not able to attack, because he doesn't have enough hit points.\033[0m" << std::endl, void());
    // set_energyPoints(energyPoints - 1);
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    // set_attackDamage(attackDamage + 1);
    attackDamage++;
}

void ScavTrap::guardGate()
{
    if (gate == 0)
    {
        std::cout << "ScavTrap " << name << " has entered in Gate keeper mode." << std::endl;
        gate = 1;
        return;
    }
    else
        std::cout << "\033[31mScavTrap " << name << " is already in Gate keeper mode.\033[0m" << std::endl;
}