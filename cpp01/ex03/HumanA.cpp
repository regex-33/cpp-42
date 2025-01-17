#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
    if (this->weapon.getType() == "")
        std::cout << "HumanA " << this->name << " created without a weapon" << std::endl;
    else
        std::cout << "HumanA " << this->name << " created with a " << this->weapon.getType() << std::endl;
}

void HumanA::attack() {
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA " << this->name << " destroyed" << std::endl;
}