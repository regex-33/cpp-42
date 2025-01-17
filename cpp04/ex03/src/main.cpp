#include "../includes/AMateria.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"

int main() {
  IMateriaSource *src = new MateriaSource();
  std::cout << "-------------------------------" << std::endl;
  src->learnMateria(new Ice());
  std::cout << "-------------------------------" << std::endl;
  src->learnMateria(new Cure());
  std::cout << "-------------------------------" << std::endl;

  ICharacter *me = new Character("me");
  std::cout << "-------------------------------" << std::endl;
  AMateria *tmp;
  std::cout << "-------------------------------" << std::endl;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  std::cout << "-------------------------------" << std::endl;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  me->unequip(0);
  std::cout << "-------------------------------" << std::endl;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  me->unequip(1);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  std::cout << "-------------------------------" << std::endl;
  me->unequip(2);
  me->unequip(3);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  me->unequip(0);
  std::cout << "-------------------------------" << std::endl;
  ICharacter *bob = new Character("bob");
  std::cout << "-------------------------------" << std::endl;
  me->use(0, *bob);
  me->use(1, *bob);
  std::cout << "-------------------------------" << std::endl;
  delete bob;
  delete me;
  delete src;
  return 0;
}
