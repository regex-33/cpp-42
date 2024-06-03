#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>


/*


the `typename` keyword is used in template programming as a way to identify nested dependent types. 

When you're writing a template, the compiler doesn't know in advance what types will be used as template arguments. This means that when you write something like `T::const_iterator`, the compiler doesn't know whether `const_iterator` is a type or a static member of `T`.

The `typename` keyword is used to tell the compiler that a name represents a type. This is necessary because the compiler needs to know this information to correctly parse the program.

`typename T::const_iterator` tells the compiler that `T::const_iterator` is a type. This is necessary because `T` is a template parameter, and `const_iterator` is a dependent name - its meaning depends on what `T` is. The `typename` keyword is used to clarify that `T::const_iterator` is a type, not a static member or something else.



*/
template <typename T>
typename T::const_iterator easyfind(T const &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return it;
}

#endif