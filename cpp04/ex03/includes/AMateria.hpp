#pragma once
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria {
protected:
  std::string _type;

public:
  AMateria();
  AMateria(const std::string &type);
  AMateria(const AMateria &copy);
  virtual ~AMateria();

  AMateria &operator=(const AMateria &copy);

  const std::string &getType() const;

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target) = 0;
};
