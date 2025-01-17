#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : virtual public Animal {
private:
  Brain *brain;

public:
  Cat();
  ~Cat();
  Cat(const Cat &copy);
  Cat &operator=(const Cat &copy);
  void makeSound() const;
  std::string getIdea(int i) const;
  void getIdeas() const;
  void setIdea(int i, std::string idea);
};
