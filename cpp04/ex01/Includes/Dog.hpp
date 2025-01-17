#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal {
private:
  Brain *brain;

public:
  Dog();
  ~Dog();
  Dog(const Dog &copy);
  Dog &operator=(const Dog &copy);
  void makeSound() const;
  std::string getIdea(int i) const;
  void getIdeas() const;
  void setIdea(int i, std::string idea);
};
