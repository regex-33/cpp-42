#include "../Includes/PmergeMe.hpp"
// -----------------------------------------------------------------------------
// vector
// -----------------------------------------------------------------------------

void Pmergeme::VparseNumbersFromArgs(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    std::stringstream ss(argv[i]);
    int num;

    while (ss >> num) {
      this->MergeVector.push_back(num);
    }
  }
}

IntVector Pmergeme::MinsOne(const IntVector &sequence) {
  IntVector finalsequence;
  for (unsigned long i = 0; i < sequence.size() && i < this->VLowest.size() + 1;
       i++) {
    if (sequence[i] - 1 < static_cast<int>(this->VLowest.size()))
      finalsequence.push_back(sequence[i] - 1);
  }
  return (finalsequence);
}

IntVector Pmergeme::fillMissingNumbers(const IntVector &inputSequence) {
  IntVector fullSequence;
  for (size_t i = 0; i < inputSequence.size(); i++) {
    fullSequence.push_back(inputSequence[i]);

    for (int num = inputSequence[i - 1] + 1;
         num != inputSequence[i] && num < inputSequence[i]; ++num) {
      if (i > 0) { // Prevent accessing inputSequence[i - 1] when i == 0
        if (num >= 2)
          fullSequence.push_back(num);
      }
    }
  }
  return this->MinsOne(fullSequence);
}

IntVector Pmergeme::VectorjacobsthalSequence(unsigned long n) {
  IntVector tmp;
  IntVector sequence;

  // base cases
  if (n >= 1)
    tmp.push_back(0); // j(0)
  if (n >= 2)
    tmp.push_back(1); // j(1)

  for (unsigned long i = 2; i < n && i < 20; ++i) {
    int nextterm = tmp[i - 1] + 2 * tmp[i - 2];
    tmp.push_back(nextterm);
    sequence.push_back(nextterm);
  }
  // std::cout << "hi hello" << std::endl;
  // for (unsigned int i = 0; i < sequence.size(); i++)
  //   std::cout << sequence[i] << " ";

  return fillMissingNumbers(sequence);
}

// Insert elements from `VLowest` into `VLargest` using binary search
void insertElements(IntVector &VLargest, const IntVector &VLowest,
                    const IntVector &seq) {
  for (IntVector::const_iterator it = seq.begin(); it != seq.end(); ++it) {
    if (*it < static_cast<int>(VLowest.size())) { // Ensure the index is valid
      IntVectorIterator pos =
          std::lower_bound(VLargest.begin(), VLargest.end(), VLowest[*it]);
      VLargest.insert(pos, VLowest[*it]);
    }
  }
}

// Ford-Johnson algorithm implementation
void Pmergeme::VectorMerge(int argc, char **argv) {
  this->VparseNumbersFromArgs(argc, argv);

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

  // Populate `VLargest` and `VLowest` vectors
  for (VectorOfPairsIterator it = VectorPairs.begin(); it != VectorPairs.end();
       ++it) {
    this->VLargest.push_back(it->first);
    this->VLowest.push_back(it->second);
  }

  // Sort `VLargest`
  std::sort(this->VLargest.begin(), this->VLargest.end());

  IntVector seq = VectorjacobsthalSequence(this->VLowest.size());
  // std::cout << "--------------------------" << std::endl;

  // Insert the first element of VLowest into VLargest
  // if (!this->VLowest.empty()) {
  //   if (std::find(this->VLargest.begin(), this->VLargest.end(),
  //                 this->VLowest[0]) == this->VLargest.end()) {
  //     this->VLargest.insert(this->VLargest.begin(), this->VLowest[0]);
  //   }
  // }
  // Insert remaining elements from `VLowest` into `VLargest`
  insertElements(this->VLargest, this->VLowest, seq);
  if (hasOddElement) {
    IntVectorIterator pos = std::lower_bound(this->VLargest.begin(),
                                             this->VLargest.end(), oddElement);
    this->VLargest.insert(pos, oddElement);
  }
}

// -----------------------------------------------------------------------------
// deque
// -----------------------------------------------------------------------------

void Pmergeme::DparseNumbersFromArgs(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    std::stringstream ss(argv[i]);
    int num;

    while (ss >> num) {
      this->MergeDeque.push_back(num);
    }
  }
}

IntDeque Pmergeme::MinsOne(const IntDeque &sequence) {
  IntDeque finalsequence;
  for (unsigned long i = 0; i < sequence.size() && i < this->DLowest.size() + 1;
       i++) {
    if (sequence[i] - 1 < static_cast<int>(this->DLowest.size()))
      finalsequence.push_back(sequence[i] - 1);
  }
  return (finalsequence);
}

IntDeque Pmergeme::fillMissingNumbers(const IntDeque &inputSequence) {
  IntDeque fullSequence;
  for (size_t i = 0; i < inputSequence.size(); i++) {
    fullSequence.push_back(inputSequence[i]);
    if (i > 0) { // Prevent accessing inputSequence[i - 1] when i == 0
      for (int num = inputSequence[i - 1] + 1; num < inputSequence[i]; ++num) {
        if (num >= 2)
          fullSequence.push_back(num);
      }
    }
  }

  return this->MinsOne(fullSequence);
}

IntDeque Pmergeme::DequejacobsthalSequence(unsigned long n) {
  IntDeque tmp;
  IntDeque sequence;

  // base cases
  if (n >= 1)
    tmp.push_back(0); // j(0)
  if (n >= 2)
    tmp.push_back(1); // j(1)

  // calculate the remaining terms
  for (unsigned long i = 2; i < n && i < 20; ++i) {
    int nextterm = tmp[i - 1] + 2 * tmp[i - 2];
    tmp.push_back(nextterm);
    sequence.push_back(nextterm);
  }
  return fillMissingNumbers(sequence);
}
void insertElements(IntDeque &DLargest, const IntDeque &DLowest,
                    const IntDeque &seq) {
  for (IntDeque::const_iterator it = seq.begin(); it != seq.end(); ++it) {
    if (*it >= 0 &&
        *it < static_cast<int>(DLowest.size())) { // Ensure the index is valid
      IntDequeIterator pos =
          std::lower_bound(DLargest.begin(), DLargest.end(), DLowest[*it]);
      DLargest.insert(pos, DLowest[*it]);
    }
  }
}

// Insert elements from `DLowest` into `DLargest` using binary search
// void insertElements(IntDeque &DLargest, const IntDeque &DLowest,
//                     const IntDeque &seq) {
//   for (IntDeque::const_iterator it = seq.begin(); it != seq.end(); ++it) {
//     if (*it < static_cast<int>(DLowest.size())) { // Ensure the index is
//     valid
//       IntDequeIterator pos =
//           std::lower_bound(DLargest.begin(), DLargest.end(), DLowest[*it]);
//       DLargest.insert(pos, DLowest[*it]);
//     }
//   }
// }

// Ford-Johnson algorithm implementation

void Pmergeme::DequeMerge(int argc, char **argv) {
  this->DparseNumbersFromArgs(argc, argv);

  if (MergeDeque.empty())
    return;

  bool hasOddElement = (MergeDeque.size() % 2 != 0);
  int oddElement = hasOddElement ? MergeDeque.back() : 0;

  for (unsigned long i = 0; i + 1 < MergeDeque.size(); i += 2) {
    if (MergeDeque[i] > MergeDeque[i + 1]) {
      this->DequePairs.push_back(
          std::make_pair(MergeDeque[i], MergeDeque[i + 1]));
    } else {
      this->DequePairs.push_back(
          std::make_pair(MergeDeque[i + 1], MergeDeque[i]));
    }
  }

  std::sort(DequePairs.begin(), DequePairs.end());
  for (DequeOfPairsIterator it = DequePairs.begin(); it != DequePairs.end();
       ++it) {
    this->DLargest.push_back(it->first);
    this->DLowest.push_back(it->second);
  }
  std::sort(this->DLargest.begin(), this->DLargest.end());

  IntDeque seq = DequejacobsthalSequence(this->DLowest.size());
  insertElements(this->DLargest, this->DLowest, seq);

  if (hasOddElement) {
    IntDequeIterator pos = std::lower_bound(this->DLargest.begin(),
                                            this->DLargest.end(), oddElement);
    this->DLargest.insert(pos, oddElement);
  }
}
