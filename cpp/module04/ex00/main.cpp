#include "Dog.hpp"

int main()
{
    const Animal* i = new Animal();
    const Animal* j = new Dog();

    i->makeSound();
    j->makeSound();

    delete i;
    delete j;
    
    return 0;
}
