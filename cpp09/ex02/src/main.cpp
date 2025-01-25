#include "../Includes/PmergeMe.hpp"

int main(int argc, char **argv) {
  Pmergeme data;
  if (argc < 2)
    return (std::cerr << "Error" << std::endl, 1);
  // --------------------------------------------------------------------
  // Vecort
  // --------------------------------------------------------------------
  clock_t start_time = clock();
  data.VectorMerge(argc, argv);
  std::cout << "Befor: ";
  data.PrintVector();
  std::cout << "After: ";
  data.VPrintLargest();
  clock_t end_time = clock();

  // Calculate the elapsed time in microseconds
  double elapsed_time =
      static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

  // Print the result using std::cout with fixed precision
  std::cout << "Time to process a range of " << data.getMergeVectorSize()
            << " elements with std::vector : " << std::fixed
            << std::setprecision(5) << elapsed_time << " us" << std::endl;

  // --------------------------------------------------------------------
  // Deque
  // --------------------------------------------------------------------
  start_time = clock();
  data.DequeMerge(argc, argv);
  std::cout << "Befor: ";
  data.PrintDeque();
  std::cout << "After: ";
  data.DPrintLargest();
  end_time = clock();

  // Calculate the elapsed time in microseconds
  elapsed_time =
      static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;

  // Print the result using std::cout with fixed precision
  std::cout << "Time to process a range of " << data.getMergeDequeSize()
            << " elements with std::deque : " << std::fixed
            << std::setprecision(5) << elapsed_time << " us" << std::endl;

  // --------------------------------------------------------------------
  // --------------------------------------------------------------------
  // --------------------------------------------------------------------
  // --------------------------------------------------------------------
  // std::string input(argv[1]);
  // data.VectorMerge(argc, argv);
  // std::cout << "Vecort --------------------------------:" << std::endl;
  // data.PrintVector();
  // std::cout << "printVectorPairs :" << std::endl;
  // data.printVectorPairs();
  // std::cout << "Largest :" << std::endl;
  // data.VPrintLargest();
  // std::cout << "Lowest:" << std::endl;
  // data.VPrintLowest();
  // std::cout << "-----------------------------" << std::endl;
  // std::cout << "Largest :" << std::endl;
  // data.VPrintLargest();
  // std::cout << "-----------------------------" << std::endl;
  //
  // std::cout << "Deque --------------------------------:" << std::endl;
  // data.DequeMerge(argc, argv);
  // std::cout << "Largest :" << std::endl;
  // data.DPrintLargest();
  // std::cout << "-----------------------------" << std::endl;
  // data.PrintVector();
  // data.DequeMerge(input);
  return 0;
}
