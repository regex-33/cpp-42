#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType();
    void setType(std::string type);
};

class HumanB
{
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(std::string name);
   // HumanB(const char* name); // Declaration of constructor
    ~HumanB();
    void setWeapon(Weapon& weapon);
    void attack();
};

class HumanA
{
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack();
};

#endif
