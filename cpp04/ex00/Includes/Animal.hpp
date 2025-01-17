#pragma once
#include <iostream>

class Animal {
protected:
  std::string _type;

public:
  Animal();
  virtual ~Animal();
  Animal(const Animal &copy);
  Animal &operator=(const Animal &copy);
  void setType(std::string type);
  virtual void makeSound() const;
  std::string getType() const;
};
