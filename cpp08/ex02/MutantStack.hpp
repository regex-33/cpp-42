#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>

#include <stack>

/*
The stack "underlying container" is deque by default, but can be a vector or a list as well. It's important to know this to answer your question because we are going to use the iterator of the underlying container to make MyStack iterable


this is the template for the stack class defined in stl_stack.h:

template<typename _Tp, typename _Sequence = deque<_Tp> >
class stack {...}

The second template parameter is the underlying container type. The default is deque<_Tp>, but you can change it to vector<_Tp> or list<_Tp> if you want. The underlying container is the container that holds the elements of the stack. The stack class is a container adapter, which means it uses another container to store its elements. The stack class provides a LIFO (last-in, first-out) data structure, and it uses the underlying container to store the elements in the stack.
*/
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack(void) : std::stack<T, Container>() {}
        ~MutantStack(void) {}

        typedef typename Container::iterator iterator;

        iterator    begin(void) {
            return (this->c.begin());
        }

        iterator    end(void) {
            return (this->c.end());
        }
};

#endif