#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &other) { *this = other; }

Span &Span::operator=(Span const &other) {
  if (this != &other) {
    _n = other._n;
    _v = other._v;
  }
  return (*this);
}

Span::~Span() {}

void Span::addNumber(int n) {
  if (std::find(_v.begin(), _v.end(), n) != _v.end())
    throw std::exception();
  _v.push_back(n);
}

int Span::shortestSpan() {
  int min = INT_MAX;
  if (_v.size() < 2)
    throw std::exception();
  std::sort(_v.begin(), _v.end());
  for (size_t i = 0; i < _v.size() - 1; i++) {
    if (_v[i + 1] - _v[i] < min)
      min = _v[i + 1] - _v[i];
  }
  return (min);
}

int Span::longestSpan() {
  if (_v.size() < 2)
    throw std::exception();
  std::sort(_v.begin(), _v.end());
  return (_v[_v.size() - 1] - _v[0]);
}

void Span::addrandomNumber(size_t NumberOfRandomNumbers) {

  srand(time(NULL));
  for (size_t i = 0; i < NumberOfRandomNumbers; i++)
    addNumber(rand());
}
