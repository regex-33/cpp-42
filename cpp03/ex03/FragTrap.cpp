#include "ClapTrap.hpp"

FragTrap::FragTrap(const FragTrap&copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    gate = copy.gate;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    ClapTrap::operator=(copy);
    gate = copy.gate;
    return (*this);
}

FragTrap::FragTrap() : ClapTrap(), gate(0)
{
    std::cout << "FragTrap default constructor called" << std::endl;
    hitpoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), gate(0)
{
    name = name + "_clap_name";
    std::cout << "FragTrap constructor from name " << name << " called" << std::endl;
    hitpoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructor called" << std::endl;   // Remove the redeclaration of ClapTrap::~ClapTrap() here
}


void FragTrap::highFivesGuys(void)
{
    if (hitpoints == 0)
        return (std::cout << "\033[31mFragTrap " << name << " is not able to give a high five, because he doesn't have enough hit points.\033[0m" << std::endl, void());
    // set_energyPoints(energyPoints - 1);
    energyPoints--;
    std::cout << "FragTrap " << name << " gives a high five to his friends!" << std::endl;
    // set_attackDamage(attackDamage + 1);
    attackDamage++;
}