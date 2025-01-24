#include "../Includes/PmergeMe.hpp"
#include <iterator>

// Parse numbers from command-line arguments
IntVector parseNumbersFromArgs(int argc, char *argv[]) {
  IntVector numbers;

  for (int i = 1; i < argc; ++i) {
    std::stringstream ss(argv[i]);
    int num;

    while (ss >> num) {
      numbers.push_back(num);
    }
  }

  return numbers;
}
//
IntVector Pmergeme::MinsOne(const IntVector &sequence) {
  IntVector finalsequence;
  for (unsigned long i = 0; i < sequence.size() && i < this->Lowest.size() + 1;
       i++) {
    if (sequence[i] - 1 < static_cast<int>(this->Lowest.size()))
      finalsequence.push_back(sequence[i] - 1);
  }
  return (finalsequence);
}

IntVector Pmergeme::fillMissingNumbers(const IntVector &inputSequence) {
  IntVector fullSequence;
  // fullSequence.push_back(inputSequence[]);
  std::cout << "Regex numbers: ";
  for (unsigned int num = 0; num < inputSequence.size(); num++) {
    std::cout << inputSequence[num] << " ";
  }
  for (size_t i = 0; i < inputSequence.size(); i++) {
    fullSequence.push_back(inputSequence[i]);

    for (int num = inputSequence[i - 1] + 1;
         num != inputSequence[i] && num < inputSequence[i]; ++num) {
      if (num >= 2)
        fullSequence.push_back(num);
    }
  }

  // std::cout << "Befor Mins Seq numbers: ";
  // for (unsigned int num = 0; num < fullSequence.size(); num++) {
  //   std::cout << fullSequence[num] << " ";
  // // }
  // for (unsigned int num = 0; num < fullSequence.size(); num++) {
  //   fullSequence[num] = fullSequence[num] - 1;
  // }
  return this->MinsOne(fullSequence);
}

IntVector Pmergeme::jacobsthalsequence(unsigned long n) {
  IntVector tmp;
  IntVector sequence;

  // base cases
  if (n >= 1)
    tmp.push_back(0); // j(0)
  if (n >= 2)
    tmp.push_back(1); // j(1)

  // calculate the remaining terms
  for (unsigned long i = 2; i < n; ++i) {
    int nextterm = tmp[i - 1] + 2 * tmp[i - 2];
    tmp.push_back(nextterm);
    // if (i > 2 || )
    sequence.push_back(nextterm);
    // std::cout << "i : " << nextterm;
  }
  // std::cout << n << "-----------numbers: ";
  // for (unsigned long i = 0; i < sequence.size(); i++) {
  //   std::cout << sequence[i] << " ";
  // }
  // std::cout << std::endl;
  // std::cout << "-----------++++++++++++++++: ";

  return fillMissingNumbers(sequence);
  // return finalsequence;
}

// Insert elements from `Lowest` into `Largest` using binary search
void insertElements(IntVector &Largest, const IntVector &Lowest,
                    const IntVector &seq) {
  for (IntVector::const_iterator it = seq.begin(); it != seq.end(); ++it) {
    if (*it < static_cast<int>(Lowest.size())) { // Ensure the index is valid
      IntVectorIterator pos =
          std::lower_bound(Largest.begin(), Largest.end(), Lowest[*it]);
      Largest.insert(pos, Lowest[*it]);
    }
  }
}

// Ford-Johnson algorithm implementation
void Pmergeme::VectorMerge(int argc, char **argv) {
  this->MergeVector = parseNumbersFromArgs(argc, argv);

  // If the number of elements is odd, handle the last element separately
  bool hasOddElement = (MergeVector.size() % 2 != 0);
  int oddElement = hasOddElement ? MergeVector.back() : 0;

  // Create pairs and sort them
  for (unsigned long i = 0; i + 1 < MergeVector.size(); i += 2) {
    if (MergeVector[i] > MergeVector[i + 1]) {
      this->VectorPairs.push_back(
          std::make_pair(MergeVector[i], MergeVector[i + 1]));
    } else {
      this->VectorPairs.push_back(
          std::make_pair(MergeVector[i + 1], MergeVector[i]));
    }
  }

  // Sort pairs by the larger element
  std::sort(VectorPairs.begin(), VectorPairs.end());

  // Populate `Largest` and `Lowest` vectors
  for (VectorOfPairsIterator it = VectorPairs.begin(); it != VectorPairs.end();
       ++it) {
    this->Largest.push_back(it->first);
    this->Lowest.push_back(it->second);
  }

  // Sort `Largest`
  std::sort(this->Largest.begin(), this->Largest.end());

  // Generate Jacobsthal sequence
  IntVector seq = jacobsthalsequence(this->Lowest.size());

  // Insert the first element of Lowest into Largest
  // if (!this->Lowest.empty()) {
  //   if (std::find(this->Largest.begin(), this->Largest.end(),
  //                 this->Lowest[0]) == this->Largest.end()) {
  //     this->Largest.insert(this->Largest.begin(), this->Lowest[0]);
  //   }
  // }
  // Insert remaining elements from `Lowest` into `Largest`
  insertElements(this->Largest, this->Lowest, seq);

  // If there was an odd element, insert it into `Largest`
  std::cout << "Seq numbers: ";
  for (IntVectorIterator it = seq.begin(); it != seq.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "----- Pairs -----" << std::endl;
  printVectorPairs();
  // std::sort(this->Largest.begin(), this->Largest.end());
  std::cout << "----- Lowest -----" << std::endl;
  PrintLowest();
  std::cout << "----- Largest -----" << std::endl;
  PrintLargest();
  // exit(9);
  if (hasOddElement) {
    IntVectorIterator pos = std::lower_bound(this->Largest.begin(),
                                             this->Largest.end(), oddElement);
    this->Largest.insert(pos, oddElement);
  }

  // Print the sorted vector
  std::cout << "Sorted numbers: ";
  for (IntVectorIterator it = this->Largest.begin(); it != this->Largest.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  exit(9);
}
