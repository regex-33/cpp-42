#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() :  ScavTrap(), FragTrap()
{
    std::cout << "\nDiamondTrap default constructor called\n\n" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
    this->_name = name + "_clap_name";
    std::cout << "DiamondTrap name constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ScavTrap(copy), FragTrap(copy)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = copy;
}


DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        ScavTrap::hitpoints = copy.ScavTrap::hitpoints;
        FragTrap::hitpoints = copy.FragTrap::hitpoints;
        ScavTrap::energyPoints = copy.ScavTrap::energyPoints;
        FragTrap::energyPoints = copy.FragTrap::energyPoints;
        ScavTrap::attackDamage = copy.ScavTrap::attackDamage;
        FragTrap::attackDamage = copy.FragTrap::attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}


void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->ScavTrap::name << std::endl;
}

