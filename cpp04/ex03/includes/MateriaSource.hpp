#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *_materias[4];
  int _count;

public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(MateriaSource const &src);
  MateriaSource &operator=(MateriaSource const &rhs);
  void learnMateria(AMateria *materia);
  AMateria *createMateria(std::string const &type);
};
