#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

Animal *meta[10];

void del()
{
    std::cout << "=================== 소멸의 순서 ===================" << std::endl;

    for (size_t i = 0; i < 10; i++)
    {
        if (meta[i] != NULL)
        {
            delete meta[i];
            meta[i] = NULL;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void test3()
{
    std::cout << "=================== 복사의 순서 ===================" << std::endl;

    Dog *d = new Dog();

    d->getBrain()->setIdea("주인 나 배고프다...", 0);
    d->getBrain()->setIdea("주인 나 산책 가고싶다....", 1);

    std::cout << "강아지의 첫번째 생각 : " << d->getBrain()->getIdea(0) << std::endl;
    std::cout << "강아지의 두번째 생각 : " << d->getBrain()->getIdea(1) << std::endl;

    Dog *d2 = new Dog(*d);

    std::cout << "강아지의 첫번째 생각 : " << d2->getBrain()->getIdea(0) << std::endl;
    std::cout << "강아지의 두번째 생각 : " << d2->getBrain()->getIdea(1) << std::endl;

    std::cout << std::endl;
}

void test1()
{
    std::cout << "================== 생성자의 순서 ==================" << std::endl;

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
