#include "../Includes/Data.hpp"

Data::Data() : id(0), name("Default"), value(0.0f) {
  std::cout << "Data default constructor called.\n";
}

Data::Data(int id, const std::string &name, float value)
    : id(id), name(name), value(value) {
  std::cout << "Data parameterized constructor called.\n";
}

Data::Data(const Data &other)
    : id(other.id), name(other.name), value(other.value) {
  std::cout << "Data copy constructor called.\n";
}

Data &Data::operator=(const Data &other) {
  if (this != &other) {
    id = other.id;
    name = other.name;
    value = other.value;
    std::cout << "Data copy assignment operator called.\n";
  }
  return *this;
}

Data::~Data() { std::cout << "Data destructor called.\n"; }

int Data::getId() const { return id; }

std::string Data::getName() const { return name; }

float Data::getValue() const { return value; }
