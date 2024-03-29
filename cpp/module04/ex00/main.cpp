#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();

    j->makeSound();
    delete j;
    return 0;
}
