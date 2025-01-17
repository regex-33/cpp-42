#pragma once

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria {
public:
  Cure();
  virtual ~Cure();
  Cure(Cure const &copy);
  Cure &operator=(Cure const &rhs);
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};
