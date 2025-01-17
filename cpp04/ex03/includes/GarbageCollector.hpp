#pragma once
#include "AMateria.hpp"
// #include "Node.hpp"

// class FreeMemmory {
// private:
//   Node *head;
//
// public:
//   FreeMemmory();
//   ~FreeMemmory();
//   FreeMemmory &operator=(const FreeMemmory &other);
//   FreeMemmory(const FreeMemmory &other);
//
//   void add_back(Node *materia);
//   Node *get_head();
//   void set_head(Node *head);
//   // void print() const;
//   void clear();
// };
//
class GarbageCollector {
private:
  AMateria **garbage; // Array of pointers to store garbage AMateria*
  int capacity;       // Current capacity of the array
  int size;           // Current number of elements in the garbage

  void expand();

public:
  GarbageCollector();
  GarbageCollector(const GarbageCollector &other);

  GarbageCollector &operator=(const GarbageCollector &other);
  ~GarbageCollector();

  // Add an AMateria* to the garbage collector
  void add(AMateria *materia);

  // Free all stored AMateria pointers and reset the garbage list
  void clear();
};
