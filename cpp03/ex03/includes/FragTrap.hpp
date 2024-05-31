#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/*
GitHub Copilot: The error messages indicate that `ClapTrap` is not a direct or virtual base of `DiamondTrap`. This is because `DiamondTrap` is trying to inherit from `ClapTrap` through multiple paths (`ScavTrap` and `FragTrap`), which is causing ambiguity.

To resolve this, you should use virtual inheritance. Virtual inheritance is a C++ technique that ensures only one copy of a base class's member variables are inherited by grandchild derived classes.

Here's how you can modify your classes:

```cpp
class ClapTrap
{
    //...
};

class ScavTrap : virtual public ClapTrap
{
    //...
};

class FragTrap : virtual public ClapTrap
{
    //...
};

class DiamondTrap : public ScavTrap, public FragTrap
{
    //...
};
```

This way, `DiamondTrap` will only inherit one copy of `ClapTrap`'s member variables, even though it's indirectly inheriting from `ClapTrap` through two paths (`ScavTrap` and `FragTrap`). This should resolve the ambiguity and fix the compilation errors.
*/
class FragTrap : virtual public ClapTrap 
{
    private:
        int gate;
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif