
#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class Rpn {
private:
  std::stack<int> rpnStack;

public:
  ~Rpn() {}
  Rpn() {}

  Rpn(const Rpn &other) { *this = other; }

  Rpn &operator=(const Rpn &other) {
    (void)other;
    return *this;
  }
  bool parseRPN(const std::string &input);
  bool isValidNumber(const std::string &token);
  bool isOperator(const std::string &token);
};

#endif
