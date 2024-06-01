#ifndef AMATEIA_HPP
#define AMATEIA_HPP

#include <iostream>
#include <string>

/*GitHub Copilot: The error message is indicating that the type `ICharacter` is not recognized in the `AMateria.hpp` file. This could be due to a circular dependency issue, where `AMateria.hpp` includes `ICharacter.hpp`, and `ICharacter.hpp` in turn includes `AMateria.hpp`.

To resolve this issue, you can use forward declaration. Forward declaration allows you to tell the compiler that a specific type exists without having to include the header file where it's defined.

Here's how you can modify your `AMateria.hpp` file:

```cpp
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter; // Forward declaration

class AMateria
{
    protected:
        std::string _type;
        unsigned int _xp;
    public:
        AMateria();
        AMateria(const std::string &type);
        AMateria(const AMateria &copy);
        virtual ~AMateria();

        AMateria &operator=(const AMateria &copy);

        const std::string &getType() const;
        unsigned int getXP() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target) = 0; // Now ICharacter is recognized
};

#endif
```

Remember to include the `ICharacter.hpp` file in the `AMateria.cpp` file where you implement the `use` function.*/


class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        unsigned int _xp;
    public:
        AMateria();
        AMateria(const std::string &type);
        AMateria(const AMateria &copy);
        virtual ~AMateria();

        AMateria &operator=(const AMateria &copy);

        const std::string &getType() const;
        unsigned int getXP() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target) = 0;
};


#endif