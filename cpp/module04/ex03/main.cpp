#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// #include <cstdlib> // for system and atexit
// void f()
// {
//     system("leaks ex03");
// }

int main()
{
    // atexit(*f);
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    Character* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    // me->unequip(1);
    // // me 복사생성
    // Character* me2 = new Character(*me);
    // me2->unequip(0);
    // delete me2;

    delete bob;
    delete me;
    delete src;
    return 0;
}