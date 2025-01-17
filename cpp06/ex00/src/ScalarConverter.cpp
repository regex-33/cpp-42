#include "../Includes/ScalarConverter.hpp"
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

void ScalarConverter::convert(const std::string &literal) {
  char value;
  if (isChar(literal)) {
    value = static_cast<unsigned char>(literal[0]);
    if (literal[0] == '0')
      value = static_cast<unsigned char>(0);
    else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
      value = static_cast<unsigned char>(literal[1]);
    printChar(value);
  } else if (isInt(literal)) {
    int value = std::atoi(literal.c_str());
    printInt(value);
  } else if (isFloat(literal)) {
    float value = std::strtof(literal.c_str(), 0);
    printFloat(value);
  } else if (isDouble(literal)) {
    double value = std::strtod(literal.c_str(), 0);
    printDouble(value);
  } else {
    // Invalid literal
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
}

bool ScalarConverter::isChar(const std::string &literal) {
  return (literal.length() == 1 ||
          (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\''));
}

bool ScalarConverter::isInt(const std::string &literal) {
  char *end;
  long value = std::strtol(literal.c_str(), &end, 10);
  return *end == '\0' && value >= INT_MIN && value <= INT_MAX;
}

bool ScalarConverter::isFloat(const std::string &literal) {
  if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    return true;
  char *end;
  std::strtof(literal.c_str(), &end);
  return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string &literal) {
  if (literal == "-inf" || literal == "+inf" || literal == "nan")
    return true;
  char *end;
  std::strtod(literal.c_str(), &end);
  return *end == '\0';
}

void ScalarConverter::printChar(char value) {
  std::cout << "char: ";
  if (static_cast<int>(value) < 0 || static_cast<int>(value) >= 127)
    std::cout << "impossible\n";
  else if (std::isprint(static_cast<int>(value)))

    std::cout << "'" << value << "'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;

  // if (std::isprint(value)) {
  //   std::cout << "char': '" << value << "'" << std::endl;
  // } else {
  //   std::cout << "char: Non displayable" << std::endl;
  // }
  std::cout << "int: " << static_cast<int>(value) << std::endl;
  std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::printInt(int value) {
  if (value < INT_MIN || value > INT_MAX) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  } else {
    std::cout << "char: ";
    if (value >= 0 && value <= 127 && std::isprint(value))
      std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
      std::cout << "impossible" << std::endl;

    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
  }
}

void ScalarConverter::printFloat(float value) {
  if (value < -FLT_MAX || value > FLT_MAX) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  } else {
    std::cout << "char: ";
    if (value > 0 && value <= 127 && std::isprint(static_cast<int>(value)))
      std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
      std::cout << "impossible" << std::endl;

    if (value > INT_MIN && value < INT_MAX)
      std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
      std::cout << "int: impossible" << std::endl;

    std::cout.setf(std::ios::fixed);
    std::cout << "float: " << value << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);

    std::cout << "double: " << static_cast<double>(value) << std::endl;
  }
}

void ScalarConverter::printDouble(double value) {
  if (value < -DBL_MAX || value > DBL_MAX) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  } else {
    std::cout << "char: ";
    if (value > 0 && value < 127 && std::isprint(static_cast<int>(value)))
      std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
      std::cout << "impossible" << std::endl;

    if (value >= INT_MIN && value <= INT_MAX)
      std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
      std::cout << "int: impossible" << std::endl;

    if (value >= -FLT_MAX && value <= FLT_MAX) {
      std::cout.setf(std::ios::fixed);
      std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
      std::cout.unsetf(std::ios::fixed);
    } else {
      std::cout << "float: impossible" << std::endl;
    }

    std::cout.setf(std::ios::fixed);
    std::cout << "double: " << value << std::endl;
    std::cout.unsetf(std::ios::fixed);
  }
}
