#pragma once
#include "Animal.hpp"
class Cat : public Animal {
public:
  Cat();
  ~Cat();
  Cat(const Cat &copy);
  Cat &operator=(const Cat &copy);
  void makeSound() const;
};
