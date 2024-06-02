#include "./includes/AMateria.hpp"
#include "./includes/ICharacter.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
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
        _type = copy._type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return _type;
}
