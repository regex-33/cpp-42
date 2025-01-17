#pragma once
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria {
public:
  Ice();
  virtual ~Ice();
  Ice(Ice const &copy);
  Ice &operator=(Ice const &rhs);
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};
