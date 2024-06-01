#include "includes/ICharacter.hpp" // Include this
#include "includes/AMateria.hpp" // Include this
#include "includes/Character.hpp"


Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

Character::Character(Character const &src)
{
    *this = src;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
            delete _materia[i];
    }
}

Character &Character::operator=(Character const &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            if (rhs._materia[i])
                _materia[i] = rhs._materia[i]->clone();
            else
                _materia[i] = NULL;
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = m;
            return;
        }
    }
}


void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && _materia[idx])
        _materia[idx]->use(target);
}
