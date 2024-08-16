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
    std::cout << "Pointer: ";
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A";
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B";
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C";
    }
    std::cout << std::endl;
}

void identify(Base &p)
{
    std::cout << "Reference: ";
    try
    {
        A &a = dynamic_cast<A &>(p);
        static_cast<void>(a);
        std::cout << "A";
    }
    catch (std::bad_cast &bc)
    {
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        static_cast<void>(b);
        std::cout << "B";
    }
    catch (std::bad_cast &bc)
    {
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        static_cast<void>(c);
        std::cout << "C";
    }
    catch (std::bad_cast &bc)
    {
    }
    std::cout << std::endl;
}

int main()
{
    // dynamic_cast는 기본 클래스에서 파생 클래스로 포인터 또는 참조를 캐스팅하는 데 사용됩니다.
    // dynamic_cast는 런타임에 타입을 확인하고, 타입이 맞지 않으면 NULL을 반환합니다.
    // dynamic_cast는 다형성을 지원하는 클래스 계층 구조에서만 사용할 수 있습니다.
    // dynamic_cast는 exception을 발생시키지 않고 NULL을 반환합니다.
    srand(std::time(NULL));
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}