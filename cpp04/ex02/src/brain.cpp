#include "../Includes/Brain.hpp"

Brain::Brain() {
  std::cout << "Brain default constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
    this->ideas[i] = "";
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain::Brain(const Brain &copy) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = copy;
  // this->operator=(copy);
}

Brain &Brain::operator=(const Brain &copy) {
  std::cout << "Brain assignation operator called" << std::endl;
  if (this != &copy)
    for (int i = 0; i < 100; i++)
      this->ideas[i] = copy.getIdea(i);
  return *this;
}

std::string Brain::getIdea(int i) const { return this->ideas[i]; }

void Brain::setIdea(int i, std::string idea) { this->ideas[i] = idea; }
