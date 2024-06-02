#include "includes/ICharacter.hpp" // Include this
#include "includes/AMateria.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"

class ICharacter;

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &copy)
{
    *this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
    if (this != &copy)
        _type = copy._type;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}