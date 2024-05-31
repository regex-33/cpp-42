#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name")
{
    this->_name = "default_diamond_name";
    this->hitpoints = FragTrap::hitpoints;
    this->energyPoints = ScavTrap::energyPoints; 
    this->attackDamage = FragTrap::attackDamage;

    std::cout << "\nDiamondTrap default constructor called\n\n" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) , ScavTrap(name), FragTrap(name)
{
    this->_name = name + "_clap_name";
    std::cout << "DiamondTrap name constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy) , ScavTrap(copy), FragTrap(copy)
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
        this->hitpoints = copy.hitpoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}


void DiamondTrap::whoAmI()
{
    std::cout << "hello i am DiamondTrap named " << this->_name << " i am originated from ClapTrap named " << this->ClapTrap::name << std::endl;
    //std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->ScavTrap::name << std::endl;
}

