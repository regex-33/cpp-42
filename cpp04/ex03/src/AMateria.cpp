#include "../includes/AMateria.hpp"
#include <algorithm>

AMateria::AMateria() : _type("default") {

  std::cout << "AMateria const" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {

  std::cout << "AMateria copy const" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
  *this = copy;
  std::cout << "AMateria copy assigm const" << std::endl;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &copy) {
  if (this != &copy)
    _type = copy._type;
  return *this;
}

std::string const &AMateria::getType() const { return _type; }
