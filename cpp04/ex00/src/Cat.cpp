#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() {
  this->_type = "Cat";
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &copy) : Animal(copy) {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = copy;
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat assignation operator called" << std::endl;
  if (this != &copy)
    this->_type = copy._type;
  return (*this);
}

void Cat::makeSound() const {
  std::cout << "Meeeoow Meeeoow Meeeoow Meeeoow Meeeoow" << std::endl;
}
