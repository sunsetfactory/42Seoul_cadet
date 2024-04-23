#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("Bureaucrat 1", 1);
    Bureaucrat b2("Bureaucrat 2", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    try
    {
        b1.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        b2.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    return 0;
}