#include "./includes/AMateria.hpp"
#include "./includes/ICharacter.hpp"

AMateria::AMateria() : _type("default"), _xp(0)
{
}

AMateria::AMateria(std::string const & type) : _type(type), _xp(0)
{
}

AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &copy)
{
    if (this != &copy)
    {
        _type = copy._type;
        _xp = copy._xp;
    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return _type;
}

unsigned int AMateria::getXP() const
{
    return _xp;
}
