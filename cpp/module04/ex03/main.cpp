#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void f()
{
    system("leaks ex03");
}

int main()
{
    atexit(*f);
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *ice;
    ice = src->createMateria("ice");
    me->equip(ice);
    AMateria *cure = src->createMateria("cure");
    me->equip(cure);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);
    delete me->getMateria();
    // me->unequip(1);

    // delete ice;
    // delete cure;

    delete bob;
    delete me;
    delete src;
    return 0;
}
