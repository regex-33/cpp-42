#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class ICharacter;
class AMateria;

class Cure : public AMateria
{
    public:
        Cure();
        virtual ~Cure();
        Cure(Cure const & copy);
        Cure & operator=(Cure const & rhs);
        virtual AMateria* clone() const;
        virtual void use(ICharacter &target);
};

#endif