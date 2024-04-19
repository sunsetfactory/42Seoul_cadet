#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "==========Bureaucrat test 1==========" << std::endl;
    try
    {
        Bureaucrat b1("b1", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        // std::cout << b1 << std::endl;
        // b1.incrementGrade();
        // std::cout << b1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==========Bureaucrat test 2==========" << std::endl;
    try
    {
        Bureaucrat b2("b2", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        // std::cout << b2 << std::endl;
        // b2.decrementGrade();
        // std::cout << b2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==========Bureaucrat test 3==========" << std::endl;
    try
    {
        Bureaucrat b3("b3", 0);
        std::cout << b3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==========Bureaucrat test 4==========" << std::endl;
    try
    {
        Bureaucrat b4("b4", 151);
        std::cout << b4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}