#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data {
private:
  int id;
  std::string name;
  float value;

public:
  Data();
  Data(int id, const std::string &name, float value);
  Data(const Data &other);
  Data &operator=(const Data &other);
  ~Data();

  // Getters
  int getId() const;
  std::string getName() const;
  float getValue() const;
};

#endif
