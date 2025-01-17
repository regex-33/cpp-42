#pragma once
#include <iostream>
class WrongAnimal {
protected:
  std::string _type;

public:
  WrongAnimal();
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &copy);
  WrongAnimal &operator=(const WrongAnimal &copy);
  void setType(std::string type);
  virtual void makeSound() const;
  std::string getType() const;
};
