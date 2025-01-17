#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

Cure::Cure() : AMateria("cure") { std::cout << "cure constr" << std::endl; }

Cure::~Cure() { std::cout << "cure deconstr" << std::endl; }

Cure::Cure(const Cure &copy) : AMateria(copy) {
  *this = copy;
  std::cout << "cure copy constr" << std::endl;
}

Cure &Cure::operator=(const Cure &copy) {

  std::cout << "cure copy ass constr" << std::endl;
  if (this != &copy)
    _type = copy._type;
  return *this;
}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
