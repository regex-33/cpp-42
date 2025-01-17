#pragma once
#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "GarbageCollector.hpp"

class Character : public ICharacter {
private:
  std::string _name;
  AMateria *_materia[4];

public:
  GarbageCollector collector;
  Character();
  Character(std::string const &name);
  Character(Character const &src);
  virtual ~Character();
  Character &operator=(Character const &rhs);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

  // void deleteMateria();
};
