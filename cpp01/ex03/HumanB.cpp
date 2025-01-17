#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    std::cout << "HumanB " << this->name << " created with no weapon" << std::endl;
}

HumanB::~HumanB() {
    std::cout << "HumanB " << this->name << " destroyed" << std::endl;
}

void HumanB::attack() {
    if (this->weapon)
        std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks without a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}
