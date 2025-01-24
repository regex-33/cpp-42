#include "../Includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
  Pmergeme data;
  if (argc != 2)
    return (std::cerr << "Error" << std::endl, 1);
  // std::string input(argv[1]);
  data.VectorMerge(argc, argv);
  data.PrintVector();
  std::cout << "printVectorPairs :" << std::endl;
  data.printVectorPairs();
  std::cout << "Largest :" << std::endl;
  data.PrintLargest();
  std::cout << "Lowest:" << std::endl;
  data.PrintLowest();
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Largest :" << std::endl;
  data.PrintLargest();
  std::cout << "-----------------------------" << std::endl;
  // data.PrintVector();
  // data.DequeMerge(input);
  return 0;
}
