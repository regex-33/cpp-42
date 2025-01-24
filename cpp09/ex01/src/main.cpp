#include "../Includes/RPN.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  Rpn data;
  if (argc != 2)
    return (std::cerr << "Error" << std::endl, 1);
  std::string input(argv[1]);
  data.parseRPN(input);
  return 0;
}
