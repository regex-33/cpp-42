#include "../Includes/Serializer.hpp"

Serializer::Serializer() {
  std::cout << "Serializer default constructor called.\n";
}

Serializer::Serializer(const Serializer &) {
  std::cout << "Serializer copy constructor called.\n";
}

Serializer &Serializer::operator=(const Serializer &) {
  std::cout << "Serializer copy assignment operator called.\n";
  return *this;
}

Serializer::~Serializer() { std::cout << "Serializer destructor called.\n"; }

uintptr_t Serializer::serialize(Data *ptr) {
  std::cout << "Serializer::serialize called.\n";
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  std::cout << "Serializer::deserialize called.\n";
  return reinterpret_cast<Data *>(raw);
}
