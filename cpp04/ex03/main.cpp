#include "./includes/IMateriaSource.hpp"
#include "./includes/ICharacter.hpp"
#include "./includes/AMateria.hpp"
#include "./includes/Character.hpp"
#include "./includes/IMateriaSource.hpp"
#include "./includes/Ice.hpp"
#include "./includes/Cure.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    printf("i am here\n");
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}