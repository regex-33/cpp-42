#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

Ice::Ice() : AMateria("ice") { std::cout << "ice constr" << std::endl; }

Ice::~Ice() { std::cout << "ice dconstr" << std::endl; }

Ice::Ice(Ice const &copy) : AMateria(copy) {

  *this = copy;
  std::cout << "ice copy constr" << std::endl;
}

Ice &Ice::operator=(Ice const &rhs) {

  std::cout << "ice copy assigment constr" << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
