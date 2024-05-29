#include "Zombie.hpp" 

Zombie::~Zombie(void)
{
    std::cout << "Zombie object " << this->name << " destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
    std::cout << "Zombie object " << this->name << " created" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}