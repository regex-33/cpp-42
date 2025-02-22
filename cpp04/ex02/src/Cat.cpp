#include "../Includes/Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
  this->_type = "Cat";
  this->brain = new Brain();
  if (this->brain == NULL) {
    std::cerr << "Exiting process now";
    exit(1);
  }
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete this->brain;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = copy;
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat assignation operator called" << std::endl;
  if (this == &copy)
    return (*this);
  // delete this->brain;
  this->brain = new Brain(*copy.brain);
  for (int i = 0; i < 100; i++)
    this->brain->setIdea(i, copy.brain->getIdea(i));
  return (*this);
}

void Cat::makeSound() const {
  std::cout << "Meeeoow Meeeoow Meeeoow Meeeoow Meeeoow" << std::endl;
}

std::string Cat::getIdea(int i) const { return (this->brain->getIdea(i)); }

void Cat::setIdea(int i, std::string idea) {
  if (i < 0 || i >= 100)
    return (std::cerr << "\033[31mError: Index out of bounds\033[0m"
                      << std::endl,
            void());
  this->brain->setIdea(i, idea);
}

void Cat::getIdeas() const {
  for (int i = 0; i < 100; i++)
    if (this->brain->getIdea(i) != "")
      std::cout << "Idea " << i << ": " << this->brain->getIdea(i) << std::endl;
}
