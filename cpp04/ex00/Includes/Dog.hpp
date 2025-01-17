#pragma once
#include "Animal.hpp"
class Dog : public Animal {
public:
  Dog();
  ~Dog();
  Dog(const Dog &copy);
  Dog &operator=(const Dog &copy);
  void makeSound() const;
};
