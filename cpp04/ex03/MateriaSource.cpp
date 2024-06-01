#include "./includes/IMateriaSource.hpp"



MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
    _count = 0;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}


void MateriaSource::learnMateria(AMateria *materia)
{
    if (_count < 4)
    {
        _materias[_count] = materia;
        _count++;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return (_materias[i]->clone());
    }
    return NULL;
}