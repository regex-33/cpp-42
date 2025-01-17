#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &literal);

private:
  ScalarConverter(); // Private constructor to prevent instantiation
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &);
  ScalarConverter &operator=(const ScalarConverter &);

  static bool isChar(const std::string &literal);
  static bool isInt(const std::string &literal);
  static bool isFloat(const std::string &literal);
  static bool isDouble(const std::string &literal);

  static void printChar(char value);
  static void printInt(int value);
  static void printFloat(float value);
  static void printDouble(double value);
};

#endif
