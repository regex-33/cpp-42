
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() {
  this->_type = "WrongCat";
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
  std::cout << "WrongCat assignation operator called" << std::endl;
  if (this != &copy)
    this->_type = copy._type;
  return (*this);
}

void WrongCat::makeSound() const {
  std::cout << "Meeeoow Meeeoow Meeeoow Meeeoow Meeeoow" << std::endl;
}
