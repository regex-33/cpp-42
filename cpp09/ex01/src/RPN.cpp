#include "../Includes/RPN.hpp"

bool Rpn::isOperator(const std::string &token) {
  return token == "+" || token == "-" || token == "*" || token == "/";
}

bool Rpn::isValidNumber(const std::string &token) {
  for (size_t i = 0; i < token.size(); ++i) {
    if (!std::isdigit(token[i])) {
      return false; // Not a valid number
    }
  }
  return !token.empty();
}

bool Rpn::parseRPN(const std::string &input) {
  std::istringstream iss(input);
  std::string token;

  while (iss >> token) {
    std::cout << "|" << token << "|\n";
    if (isValidNumber(token)) {
      this->rpnStack.push(std::atoi(token.c_str()));
      // std::cout << rpnStack.top() <<" | ";// Push numbers onto the stack
    } else if (isOperator(token)) {
      if (this->rpnStack.size() < 2) {
        std::cerr << "Error: Insufficient operands for operator " << token
                  << std::endl;
        return false;
      }

      // Pop two operands and apply the operator
      int b = this->rpnStack.top();
      this->rpnStack.pop();
      int a = this->rpnStack.top();
      this->rpnStack.pop();

      if (token == "+")
        this->rpnStack.push(a + b);
      else if (token == "-")
        this->rpnStack.push(a - b);
      else if (token == "*")
        this->rpnStack.push(a * b);
      else if (token == "/") {
        if (b == 0) {
          std::cerr << "Error: Division by zero" << std::endl;
          return false;
        }
        this->rpnStack.push(a / b);
      }
    } else {
      std::cerr << "Error: Invalid token \"" << token << "\"" << std::endl;
      return false;
    }
  }

  // After processing, there should be exactly one element in the stack
  if (this->rpnStack.size() != 1) {
    std::cerr << "Error: Invalid RPN expression " << this->rpnStack.size()
              << std::endl;
    //     while (!rpnStack.empty()) {
    //         std::cout << rpnStack.top() <<" ";
    //         rpnStack.pop();
    //     }
    return false;
  }

  std::cout << "Valid RPN expression. Result: " << this->rpnStack.top()
            << std::endl;
  return true;
}
