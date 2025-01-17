#pragma once

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class Brain {
private:
  std::string ideas[100];

public:
  Brain();
  ~Brain();
  Brain(const Brain &copy);

  // assignment operator
  Brain &operator=(const Brain &copy);
  std::string getIdea(int i) const;
  void setIdea(int i, std::string idea);
};
