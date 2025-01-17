#pragma once

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class Animal {
protected:
  std::string _type;

public:
  Animal();
  virtual ~Animal();
  Animal(const Animal &copy);
  Animal &operator=(const Animal &copy);
  void setType(std::string type) { this->_type = type; }
  virtual void makeSound() const;
  std::string getType() const;
};
