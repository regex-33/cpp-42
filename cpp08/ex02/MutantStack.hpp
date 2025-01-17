#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>

#include <stack>

/*
The stack "underlying container" is deque by default, but can be a vector or a
list as well. It's important to know this to answer your question because we are
going to use the iterator of the underlying container to make MyStack iterable


this is the template for the stack class defined in stl_stack.h:

template<typename _Tp, typename _Sequence = deque<_Tp> >
class stack {...}

The second template parameter is the underlying container type. The default is
deque<_Tp>, but you can change it to vector<_Tp> or list<_Tp> if you want. The
underlying container is the container that holds the elements of the stack. The
stack class is a container adapter, which means it uses another container to
store its elements. The stack class provides a LIFO (last-in, first-out) data
structure, and it uses the underlying container to store the elements in the
stack.
*/

/*
 The `this->c` refers to the **protected member variable `c`** of the
`std::stack` class, which is the container that the `std::stack` uses internally
to store its elements.

### **Where does `this->c` come from?**

1. **`std::stack` Definition**:
   - The `std::stack` class is defined in the C++ Standard Template Library
(STL).
   - Internally, `std::stack` uses a container (like `std::deque` or
`std::vector`) to manage the storage of its elements.

2. **Key Parts of `std::stack`**:
   - `std::stack` has a **protected** member variable `c` that represents the
underlying container.
   - By default, `c` is an instance of `std::deque` unless a different container
is specified as a template parameter.

3. **Why Is `this->c` Accessible?**:
   - In `MutantStack`, we inherit from `std::stack`.
   - The `c` member is **protected**, so it is accessible in the derived class
(`MutantStack`).

---

### **Protected Member in `std::stack`**

The simplified definition of `std::stack` looks like this (from `<stack>`):

```cpp
template <class T, class Container = std::deque<T>>
class stack {
protected:
    Container c; // The underlying container
public:
    // Basic stack operations
    void push(const T& value) { c.push_back(value); }
    void pop() { c.pop_back(); }
    T& top() { return c.back(); }
    const T& top() const { return c.back(); }
    bool empty() const { return c.empty(); }
    size_t size() const { return c.size(); }
};
```

Here:
- **`c`**: The container used to implement the stack.
  - By default, `std::deque<T>` is used.
  - You can specify a different container when instantiating the stack (e.g.,
`std::stack<int, std::vector<int>>`).

---

### **Accessing `this->c` in `MutantStack`**

In the `MutantStack` class, you access `c` through `this->c`:

```cpp
iterator begin(void) {
    return this->c.begin();
}

iterator end(void) {
    return this->c.end();
}
```

- **Purpose**:
  - Since `std::stack` does not directly expose iterators, you access the
iterators of the underlying container (`c`) to enable iteration.
  - `this->c.begin()` returns an iterator to the first element of the underlying
container.

---

### **Why Use `this->c`?**

- `std::stack` is a container adapter, not a container itself. It wraps another
container (`std::deque` by default) to provide stack functionality (LIFO
operations).
- `this->c` allows you to access the underlying container and its features (like
iterators) which `std::stack` does not natively provide.

Let me know if you need more details!
 */
template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack(void) : std::stack<T, Container>() {}
  ~MutantStack(void) {}

  typedef typename Container::iterator iterator;

  iterator begin(void) { return (this->c.begin()); }

  iterator end(void) { return (this->c.end()); }
};

#endif
