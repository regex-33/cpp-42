#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    set_hitpoints(100);
    set_energyPoints(50); 
    set_attackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    set_hitpoints(100);
    set_energyPoints(50); 
    set_attackDamage(20);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << get_name() << " destructor called" << std::endl;   // Remove the redeclaration of ClapTrap::~ClapTrap() here
}

void ScavTrap::attack(std::string const &target)
{
    if (check_energy(get_energyPoints()) == 0)
        return;
    if (get_hitpoints() == 0)
        return (std::cout << "\033[31mScavTrap " << target << " is not able to attack, because he doesn't have enough hit points.\033[0m" << std::endl, void());
    set_energyPoints(get_energyPoints() - 1);
    std::cout << "ScavTrap " << get_name() << " attacks " << target << ", causing " << get_attackDamage() << " points of damage!" << std::endl;
    set_attackDamage(get_attackDamage() + 1);
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (check_hitpoints(get_hitpoints(), get_name(), 0, amount) == 0)
        return;
    if (check_energy(get_energyPoints()) == 0)
        return;
    set_hitpoints(get_hitpoints() - amount);
    if (get_hitpoints() < 0)
        set_hitpoints(0);
    std::cout << "ScavTrap " << get_name() << " takes " << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (check_hitpoints_repair(get_hitpoints(), get_name(), amount) == 0)
        return;
    if (check_energy(get_energyPoints()) == 0)
        return;
    if (get_hitpoints() >= 100)
        return (std::cout << "ScavTrap " << get_name() << " is already at full health!" << std::endl, void());
    set_hitpoints(get_hitpoints() + amount);
    std::cout << "ScavTrap " << get_name() << " is repaired for " << amount << " points!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << get_name() << " has entered in Gate keeper mode." << std::endl;
}