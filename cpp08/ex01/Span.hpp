#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>
#include <ctime>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
    public:
        Span(unsigned int n);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();
        void addNumber(int n);
        void addrandomNumber(size_t NumberOfRandoms);
        int shortestSpan();
        int longestSpan();
};

#endif