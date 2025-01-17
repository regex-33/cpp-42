#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    _materias[i] = NULL;
  _count = 0;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (_materias[i])
      delete _materias[i];
  }
}

MateriaSource::MateriaSource(MateriaSource const &src) { *this = src; }

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  if (this != &rhs) {
    this->_count = rhs._count;
    for (int i = 0; i < 4; i++) {
      if (rhs._materias[i]) {
        delete _materias[i];
        _materias[i] = rhs._materias[i]->clone();
      } else {
        _materias[i] = NULL;
      }
    }
  }
  return *this;
}
void MateriaSource::learnMateria(AMateria *materia) {
  if (_count < 4) {
    _materias[_count] = materia;
    _count++;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (_materias[i] && _materias[i]->getType() == type)
      return (_materias[i]->clone());
  }
  return NULL;
}
