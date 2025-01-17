#include "../includes/Character.hpp"
#include <cstddef>
// #include "../includes/FreeMemmory.hpp"
// #include "../includes/Node.hpp"
//
Character::Character() : _name("Character_defualt") {
  std::cout << "Character const" << std::endl;
  for (int i = 0; i < 4; i++)
    _materia[i] = NULL;
}

Character::Character(std::string const &name) : _name(name) {
  std::cout << "Character const paramter" << std::endl;
  for (int i = 0; i < 4; i++)
    _materia[i] = NULL;
}

Character::Character(Character const &src) {
  *this = src;
  std::cout << "Character copy const" << std::endl;
}

Character::~Character() {
  std::cout << "Character deconst" << std::endl;
  for (int i = 0; i < 4; i++) {
    if (_materia[i])
      delete _materia[i];
  }
}

Character &Character::operator=(Character const &rhs) {
  std::cout << "Character copy assigment const" << std::endl;
  if (this != &rhs) {
    _name = rhs._name;
    for (int i = 0; i < 4; i++) {
      if (rhs._materia[i]) {
        delete _materia[i];
        _materia[i] = rhs._materia[i]->clone();
      } else {
        _materia[i] = NULL;
      }
    }
  }
  return *this;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (!_materia[i]) {
      _materia[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    collector.add(_materia[idx]);
    _materia[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && _materia[idx])
    _materia[idx]->use(target);
}
