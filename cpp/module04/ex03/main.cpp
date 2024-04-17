#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *ice;
    ice = src->createMateria("ice");
    me->equip(ice);
    AMateria *cure = src->createMateria("cure");
    me->equip(cure);
    AMateria *fire = src->createMateria("fire");
    me->equip(fire);
    AMateria *water = src->createMateria("water");
    me->equip(water);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}
