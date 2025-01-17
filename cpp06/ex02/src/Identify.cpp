#include "../Includes/Identify.hpp"
#include "../Includes/A.hpp"
#include "../Includes/B.hpp"
#include "../Includes/C.hpp"
#include <cstdlib> // For rand, srand
#include <ctime>   // For time
#include <iostream>

// Function prototypes to create instances
Base *createA() {
  std::cout << "Generated: A\n";
  return new A();
}
Base *createB() {
  std::cout << "Generated: B\n";
  return new B();
}
Base *createC() {
  std::cout << "Generated: C\n";
  return new C();
}

Base *generate() {
  std::srand(static_cast<unsigned int>(std::time(0))); // Seed for randomness
  int randomValue = std::rand() % 3; // Generate a number between 0 and 2

  Base *(*generators[])() = {createA, createB, createC};

  return generators[randomValue]();
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "The type is: A\n";
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "The type is: B\n";
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "The type is: C\n";
  } else {
    std::cout << "Unknown type.\n";
  }
}

void identify(Base &p) { identify(&p); }
