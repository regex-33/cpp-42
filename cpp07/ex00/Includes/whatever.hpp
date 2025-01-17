#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

template <typename T> void swap(T &First, T &Second) {
  T temp;
  temp = First;
  First = Second;
  Second = temp;
}

template <typename T> T min(T &First, T &Second) {
  return (Second <= First) ? Second : First;
}

template <typename T> T max(T &First, T &Second) {
  return (Second >= First) ? Second : First;
}
#endif
