#include "../includes/GarbageCollector.hpp"
// #include "../includes/Node.hpp"

#include "../includes/AMateria.hpp"

// Helper function to expand the array when it’s full
void GarbageCollector::expand() {
  int newCapacity = capacity * 2;
  AMateria **newGarbage = new AMateria *[newCapacity];

  for (int i = 0; i < size; ++i) {
    newGarbage[i] = garbage[i];
  }

  delete[] garbage;
  garbage = newGarbage;
  capacity = newCapacity;
}

GarbageCollector::GarbageCollector() : capacity(10), size(0) {
  garbage = new AMateria *[capacity];
}

GarbageCollector::GarbageCollector(const GarbageCollector &other)
    : capacity(other.capacity), size(other.size) {
  garbage = new AMateria *[capacity];
  for (int i = 0; i < size; ++i) {
    garbage[i] = other.garbage[i];
  }
}

GarbageCollector &GarbageCollector::operator=(const GarbageCollector &other) {
  if (this != &other) {
    delete[] garbage;

    capacity = other.capacity;
    size = other.size;
    garbage = new AMateria *[capacity];
    for (int i = 0; i < size; ++i) {
      garbage[i] = other.garbage[i];
    }
  }
  return *this;
}

GarbageCollector::~GarbageCollector() {
  for (int i = 0; i < size; ++i) {
    delete garbage[i];
  }
  delete[] garbage;
}
// Expand capacity if the array is full
void GarbageCollector::add(AMateria *materia) {
  if (size == capacity) {
    expand();
  }
  garbage[size++] = materia;
}

void GarbageCollector::clear() {
  for (int i = 0; i < size; ++i) {
    delete garbage[i];
  }
  size = 0;
}
