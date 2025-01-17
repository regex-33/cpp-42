#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  this->_type = "WrongAnimal";
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
  std::cout << "WrongAnimal assignation operator called" << std::endl;
  if (this != &copy)
    this->_type = copy._type;
  return (*this);
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return (this->_type); }

void WrongAnimal::setType(std::string type) { this->_type = type; }
