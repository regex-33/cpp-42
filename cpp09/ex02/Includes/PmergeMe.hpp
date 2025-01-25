
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <iomanip>
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

// Vector
typedef std::vector<int> IntVector;
typedef std::vector<IntPair> VectorOfPairs;

// Vector iterators
typedef IntVector::iterator IntVectorIterator;
typedef VectorOfPairs::iterator VectorOfPairsIterator;


// Deque
typedef std::deque<int> IntDeque;
typedef std::deque<IntPair> DequeOfPairs;

// Deque iterators
typedef IntDeque::iterator IntDequeIterator;
typedef DequeOfPairs::iterator DequeOfPairsIterator;


class Pmergeme {
private:
  // Vector things
  IntVector MergeVector;
  VectorOfPairs VectorPairs;

  IntVector VLargest;
  IntVector VLowest;

  // deque things
  IntDeque MergeDeque;
  DequeOfPairs DequePairs;

  IntDeque DLargest;
  IntDeque DLowest;
public:
  ~Pmergeme() {}
  Pmergeme() {}

  Pmergeme(const Pmergeme &other) { *this = other; }

  Pmergeme &operator=(const Pmergeme &other) {
    (void)other;
    return *this;
  }
  // Vector 
  void VectorMerge(int argc, char **argv);
  IntVector MinsOne(const IntVector &sequence);
  IntVector fillMissingNumbers(const IntVector &inputSequence);
  IntVector VectorjacobsthalSequence(unsigned long n);
  void VparseNumbersFromArgs(int argc, char **argv);
  unsigned int getMergeVectorSize(){
    return this->MergeVector.size();
  }
  // Deque

  void DparseNumbersFromArgs(int argc, char **argv);
  void DequeMerge(int argc, char **argv);
  IntDeque MinsOne(const IntDeque &sequence);
  IntDeque fillMissingNumbers(const IntDeque &inputSequence);
  IntDeque DequejacobsthalSequence(unsigned long n);
  unsigned int getMergeDequeSize(){
    return this->MergeVector.size();
  }



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

  void PrintDeque() {
    std::cout << "Parsed numbers: ";
    for (unsigned long i = 0; i < MergeDeque.size(); i++) {
      std::cout << MergeDeque[i] << " ";
    }
    std::cout << std::endl;
  }
void printDequePairs() {
    // Iterate through the vector using a standard for loop with iterator
    std::cout << "Deque Pairs numbers: ";
    for (DequeOfPairs::const_iterator it = DequePairs.begin();
         it != DequePairs.end(); ++it) {
      std::cout << "(" << it->first << ", " << it->second << ") ";
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
  void VPrintLargest() {
    std::cout << "VLargest numbers: ";
    for (unsigned long i = 0; i < VLargest.size(); i++) {
      std::cout << VLargest[i] << " ";
    }
    std::cout << std::endl;
  }
  void DPrintLargest() {
    std::cout << "DLargest numbers: ";
    for (unsigned long i = 0; i < DLargest.size(); i++) {
      std::cout << DLargest[i] << " ";
    }
    std::cout << std::endl;
  }

  void DPrintLowest() {
    std::cout << "DLowest numbers: ";
    for (unsigned long i = 0; i < DLowest.size(); i++) {
      std::cout << DLowest[i] << " ";
    }
    std::cout << std::endl;
  }

  void VPrintLowest() {
    std::cout << "VLowest numbers: ";
    for (unsigned long i = 0; i < VLowest.size(); i++) {
      std::cout << VLowest[i] << " ";
    }
    std::cout << std::endl;
  }
};

#endif
