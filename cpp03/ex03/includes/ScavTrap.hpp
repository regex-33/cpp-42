#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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

#endif