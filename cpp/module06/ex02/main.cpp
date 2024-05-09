#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    switch (rand() % 3)
    {
    case 0:
        return (new A());
        break;
    case 1:
        return (new B());
        break;
    case 2:
        return (new C());
        break;
    default:
        perror("Something went wrong with the random generator");
        return (NULL);
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        static_cast<void>(a);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &bc)
    {
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        static_cast<void>(b);
        std::cout << "B" << std::endl;
    }
    catch (std::bad_cast &bc)
    {
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        static_cast<void>(c);
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast &bc)
    {
    }
}

int main()
{
    srand(std::time(NULL));
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}