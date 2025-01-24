
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<int, int> IntPair;

typedef std::vector<int> IntVector;
typedef std::vector<IntPair> VectorOfPairs;

typedef IntVector::iterator IntVectorIterator;
typedef VectorOfPairs::iterator VectorOfPairsIterator;


typedef std::deque<IntPair> DequeOfPairs;

class Pmergeme {
private:
  // Vector things
  std::vector<int> MergeVector;
  VectorOfPairs VectorPairs;

  std::vector<int> Largest;
  std::vector<int> Lowest;

  // deque things
  std::deque<int> MergeDeque;
  DequeOfPairs DequePairs;

public:
  ~Pmergeme() {}
  Pmergeme() {}

  Pmergeme(const Pmergeme &other) { *this = other; }

  Pmergeme &operator=(const Pmergeme &other) {
    (void)other;
    return *this;
  }
  // void VectorMerge(std::string &input);
  void VectorMerge(int argc, char **argv);
std::vector<int> MinsOne(const std::vector<int> &sequence);
std::vector<int> fillMissingNumbers(const std::vector<int> &inputSequence);
std::vector<int> jacobsthalsequence(unsigned long n);
  // --------------------------------------------
  // --------------------------------------------
  // Vector Help Methods
  // --------------------------------------------
  // --------------------------------------------
  //
  void PrintVector() {
    std::cout << "Parsed numbers: ";
    for (unsigned long i = 0; i < MergeVector.size(); i++) {
      std::cout << MergeVector[i] << " ";
    }
    std::cout << std::endl;
  }

  void printVectorPairs() {
    // Iterate through the vector using a standard for loop with iterator
    for (VectorOfPairs::const_iterator it = VectorPairs.begin();
         it != VectorPairs.end(); ++it) {
      std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
  }
  void PrintLargest() {
    std::cout << "Largest numbers: ";
    for (unsigned long i = 0; i < Largest.size(); i++) {
      std::cout << Largest[i] << " ";
    }
    std::cout << std::endl;
  }
  void PrintLowest() {
    std::cout << "Lowest numbers: ";
    for (unsigned long i = 0; i < Lowest.size(); i++) {
      std::cout << Lowest[i] << " ";
    }
    std::cout << std::endl;
  }
};

#endif
