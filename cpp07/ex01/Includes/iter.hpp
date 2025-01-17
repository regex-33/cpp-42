#ifndef ITER_HPP
#define ITER_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

template <typename Array, typename Length, typename PtrFunction>
void iter(Array *array, Length size, PtrFunction func) {
  for (size_t i = 0; i < size; ++i) {
    func(array[i]);
  }
}

#endif
