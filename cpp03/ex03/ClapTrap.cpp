#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitpoints(10), energyPoints(10), attackDamage(0)
{
    name = name + "_clap_name";
    std::cout << "ClapTrap Constructor for " << name << " called" << std::endl; 
}

ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Constactor from name " << name << " called" << std::endl; 
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Decomstructor for " << name << " called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    name = copy.name;
    hitpoints = copy.hitpoints;
    energyPoints = copy.energyPoints;
    attackDamage = copy.attackDamage;
    return (*this);
}
/* don't forget attack damge variable */

int check_energy(int energyPoints, std::string name, std::string target)
{
    if (energyPoints == 0)
        return (std::cout << "\033[31mClapTrap " << name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl, 0);
    return 1;
}

int check_hitpoints_repair(int hitpoints, std::string name, int mount)
{
    (void)mount;
    (void)name;
        //return (std::cout << "\033[31mClapTrap default is not able to repair itself, because he is already at full health.\033[0m" << std::endl, 0);
        //return (std::cout << "\033[31mClapTrap default is not able to repair itself, because he doesn't have enough hit points\033[0m" << std::endl, 0);
    if (hitpoints + mount > 10 || (hitpoints == 10 && mount > 0))
        return (std::cout << "\033[33mClapTrap " << name << " can't be repaired to have more than 10 hit points.\033[0m" << std::endl, 0);
    if (hitpoints == 0)
        return (std::cout << "\033[31mClapTrap " << name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m" << std::endl, 0);
        // return (std::cout << "\033[33mClapTrap " << name << " can't be repaired to have more than 10 hit points.\033[0m" << std::endl, 0); 
    return 1;
}

int check_hitpoints(int hitpoints, std::string name, int flag, int mount)
{
    (void)mount;
    if (flag && hitpoints == 10)
        return (std::cout << "ClapTrap " << name << " is already at full health!" << std::endl, 0);
    if (hitpoints == 0)
        return (std::cout << "\033[33mClapTrap default is already dead, stop beating it.\033[0m" << std::endl, 0);
    return 1;
}

void ClapTrap::attack(std::string const &target)
{
    if (check_energy(energyPoints, name, target) == 0) 
        return;
    if (hitpoints == 0)
        return (std::cout << "\033[31mClapTrap " << target << " is not able to attack, because he doesn't have enough hit points.\033[0m" << std::endl, void());
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    attackDamage++;
}
void ClapTrap::takeDamage(unsigned int amount)
{

    if (check_energy(energyPoints, name, name) == 0)
        return;
    if (check_hitpoints(hitpoints, name, 0, amount) == 0)
        return;
    hitpoints -= amount;
    if (hitpoints < 0)
        hitpoints = 0;
    std::cout << "ClapTrap default was attacked and lost " << amount << " hit points, he now has " << hitpoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0)
        return (std::cout << "\033[31mClapTrap " << name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m" << std::endl, void());
    if (check_hitpoints_repair(hitpoints, name, amount) == 0)
        return;
    if (energyPoints >= 10)
        return (std::cout << "\033[33mScavTrap " << name << " can't be repaired to have more than 100 hit points.\033[0m" << std::endl, void());
    energyPoints++;
    hitpoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
}