#include "../Includes/iter.hpp"

template <typename T> void printNum(T &x) { std::cout << x << " "; }

template <typename T> void multiplyByTwo(T &x) { x *= 2; }

int main() {
  int intArray[] = {1, 2, 3, 4, 5};
  size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

  std::cout << "Original integer array: ";
  iter(intArray, intArraySize, printNum<int>);
  std::cout << "\n";

  iter(intArray, intArraySize, multiplyByTwo<int>);

  std::cout << "After multiplying by two: ";
  iter(intArray, intArraySize, printNum<int>);
  std::cout << "\n";

  double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

  std::cout << "Original double array: ";
  iter(doubleArray, doubleArraySize, printNum<double>);
  std::cout << "\n";

  iter(doubleArray, doubleArraySize, multiplyByTwo<double>);

  std::cout << "After multiplying by two: ";
  iter(doubleArray, doubleArraySize, printNum<double>);
  std::cout << "\n";

  return 0;
}
