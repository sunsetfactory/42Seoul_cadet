#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

AAnimal *meta[10];
AAnimal *meta_copy[10];

Dog *d = new Dog();
Dog *d2 = new Dog();

void del()
{
    std::cout << "==================== del ====================" << std::endl;

    for (size_t i = 0; i < 10; i++)
    {
        if (meta[i] != NULL)
        {
            delete meta[i];
            meta[i] = NULL;
        }
        if (meta_copy[i] != NULL)
        {
            delete meta_copy[i];
            meta_copy[i] = NULL;
        }
        std::cout << std::endl;
    }
    if (d != NULL)
    {
        delete d;
        d = NULL;
    }
    if (d2 != NULL)
    {
        delete d2;
        d2 = NULL;
    }

    std::cout << std::endl;
}

void test3()
{
    std::cout << "==================== test3 ====================" << std::endl;

    std::string str;
    *d2 = *d;
    std::cout << std::endl;

    str = d->getBrain()->getIdea(0);
    d->makeSound();
    std::cout << "강아지의 첫번째 생각 : " << str << std::endl;

    d->getBrain()->setIdea("주인 나 배고프다...", 1);
    str = d->getBrain()->getIdea(1);
    d->makeSound();
    std::cout << "강아지의 두번째 생각 : " << str << std::endl;

    d2->getBrain()->setIdea("주인 나 산책 가고싶다....", 2);
    str = d2->getBrain()->getIdea(2);
    d2->makeSound();
    std::cout << "강아지의 세번째 생각 : " << str << std::endl;

    std::cout << std::endl;
}

void test1()
{
    std::cout << "==================== test1 ====================" << std::endl;

    for (size_t i = 0; i < 10; i++)
    {
        if (i % 2)
        {
            meta[i] = new Dog();
        }
        else
        {
            meta[i] = new Cat();
        }
    }

    std::cout << std::endl;
}

int main(void)
{
    test1();
    test3();

    del();

    return 0;
}
