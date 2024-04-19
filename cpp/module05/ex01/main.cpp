#include "Bureaucrat.hpp"
#include "Form.hpp"

void test3()
{
    std::cout << "==========Form test 3==========" << std::endl;
    try
    {
        Form form("서류3", 1, 1);
        Bureaucrat bureaucrat("seokjyan", 2);

        form.beSigned(bureaucrat);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test2()
{
    std::cout << "==========Form test 2==========" << std::endl;
    try
    {
        Form form("서류2", 1, 1);
        Bureaucrat bureaucrat("seokjyan", 1);

        form.beSigned(bureaucrat);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test1()
{
    std::cout << "==========Form test 1==========" << std::endl;
    try
    {
        Form form("서류1", 1, 1);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    test1();
    test2();
    test3();

    return 0;
}